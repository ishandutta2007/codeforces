#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
// Problem: E: Subsequences (easy version) (https://codeforces.com/contest/1183/problem/E)

using namespace std;

vector<size_t> groups(const string& s) {
    vector<size_t>  g = {1};
    char c = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] != c) {
            c = s[i];
            g.emplace_back(1);
        } else {
            g.back()++;
        }
    }

    return g;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;
    string sf;
    cin >> sf;

    set<string> se = {sf};
    queue<pair<string, vector<size_t>>> q;
    q.emplace(sf, groups(sf));

    uint64_t cost = 0;
    while (se.size() < k && !q.empty()) {
        auto [s, g] = move(q.front());
        q.pop();

        size_t si = 0;
        for (size_t i = 0; i < g.size(); ++i) {
            if (se.size() == k) {
                break;
            }

            auto s2 = s;
            s2.erase(begin(s2) + si);
            si += g[i];

            auto [it, ins] = se.emplace(s2);
            if (ins) {
                cost += sf.size() - s2.size();
                auto g2 = g;
                if (g[i] == 1) {
                    g2.erase(begin(g2) + i);
                } else {
                    g2[i]--;
                }
                q.emplace(move(s2), move(g2));
            }

        }
    }

    if (se.size() == k) {
        cout << cost << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}