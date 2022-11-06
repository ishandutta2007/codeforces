#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

using pbds_tree = tree < int ,  null_type ,  less<> ,  rb_tree_tag ,  tree_order_statistics_node_update >;

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> p[i].second >> p[i].first;
    }

    sort(begin(p), end(p), greater{});

    int last_y = 1000000001;
    uint64_t count = 0;
    vector<int> updated_xses;
    pbds_tree x_values;
    for (auto [y, x] : p) {
        if (y != last_y) {
            for (size_t i = 0; i < updated_xses.size(); ++i) {
                auto order = x_values.order_of_key(updated_xses[i]);
                uint64_t left = order + 1;
                uint64_t right;
                if (i == 0) {
                    right = x_values.size() - order;
                } else {
                    right = x_values.order_of_key(updated_xses[i - 1]) - order;
                }

                count += left * right;
            }

            last_y = y;
            updated_xses.clear();
        }

        updated_xses.emplace_back(x);
        x_values.insert(x);
    }

    for (size_t i = 0; i < updated_xses.size(); ++i) {
        auto order = x_values.order_of_key(updated_xses[i]);
        uint64_t left = order + 1;
        uint64_t right;
        if (i == 0) {
            right = x_values.size() - order;
        } else {
            right = x_values.order_of_key(updated_xses[i - 1]) - order;
        }

        count += left * right;
    }

    cout << count << '\n';

    return 0;
}