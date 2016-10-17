#include <gtest/gtest.h>

#include "toml/toml.h"

using namespace std;


TEST(FormatTest, setFormatFlags_table)
{
    toml::Value root((toml::Table()));

    EXPECT_FALSE(root.setFormatFlags(toml::FORMAT_ARRAY_MULTILINE));
    EXPECT_FALSE(root.setFormatFlags(toml::FORMAT_INDENT));

    EXPECT_TRUE(root.setFormatFlags(TINYTOML_FORMAT_FLAGS_TABLE));
}

TEST(FormatTest, write_table_inline)
{
    // XXX: TMP test
    toml::Value root((toml::Table()));
    auto nei = root.setChild ("nei", toml::Table());

    nei->setChild("a", 10);
    nei->setChild("b", 20);
    nei->setChild("c", 30);

    root.writeFormatted(&std::cout, toml::FORMAT_TABLE_INLINE);
}

