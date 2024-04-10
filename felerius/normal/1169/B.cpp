#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    int star = -1;
    int a, b;
    cin >> a >> b;

    vector<pair<int, int>> poss = {{a, star}, {b, star}};
    vector<pair<int, int>> new_poss;

    for (size_t i = 0; i < m - 1; ++i) {
        new_poss.clear();
        cin >> a >> b;
        for (auto [pa, pb] : poss) {
            if (pb == star) {
                if (a == pa || b == pa) {
                    new_poss.emplace_back(pa, star);
                } else {
                    new_poss.emplace_back(pa, a);
                    new_poss.emplace_back(pa, b);
                }
            } else {
                if (a == pa || a == pb || b == pa || b == pb) {
                    new_poss.emplace_back(pa, pb);
                }
            }
        }

        swap(poss, new_poss);
    }

    if (poss.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}