#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (27) Two Sets (Difficulty: 5) (http://codeforces.com/problemset/problem/468/B)

using namespace std;

size_t n;
int a, b;
map<int, size_t> pos;

bool find_path(bool start_a, vector<int>& path) {
    auto start = path.back();
    size_t added = 0;
    while (true) {
        auto next = (start_a ? a : b) - path.back();
        if (next == start && added > 0) {
            return true;
        }

        if (pos.find(next) == end(pos)) {
            return false;
        }

        path.emplace_back(next);
        start_a = !start_a;
        ++added;

        if (path.back() == path[path.size() - 2]) {
            return false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;

    vector<int> p(n);
    for (auto& pi : p) cin >> pi;

    for (size_t i = 0; i < n; ++i) {
        pos[p[i]] = i;
    }

    vector<int> r(n, 2);
    for (size_t i = 0; i < n; ++i) {
        if (r[i] != 2) {
            continue;
        }

        vector<int> path = {p[i]};
        bool allow_odd = false;
        bool loop_start = false;
        auto cycle = find_path(true, path);

        if (!cycle) {
            reverse(begin(path), end(path));
            find_path(false, path);
            loop_start = path[0] == path[1];
            allow_odd = loop_start || path.back() == path[path.size() - 2];
        }

        if (path.size() % 2 == 1 && !allow_odd) {
            cout << "NO\n";
            return 0;
        }

        for (size_t j = (path.size() % 2 == 1 && loop_start ? 1 : 0); j < path.size(); j += 2) {
            auto is_a = (a - path[j]) == path[j + 1];
            r[pos[path[j]]] = (is_a ? 0 : 1);
            r[pos[path[j + 1]]] = (is_a ? 0 : 1);
        }
    }

    cout << "YES\n";
    for (auto ri : r) {
        cout << ri << ' ';
    }
    cout << '\n';

    return 0;
}