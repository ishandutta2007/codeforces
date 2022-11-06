#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

// Contest: Educational Codeforces Round 72 (Rated for Div. 2) (https://codeforces.com/contest/1217)
// Problem: D: Coloring Edges (https://codeforces.com/contest/1217/problem/D)

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<pair<int,int>> e(m);
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        e[i] = {x, y};
        adj[x].push_back(y);
        indeg[y]++;
    }

    vector<int> z;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0)
            z.push_back(i);

    int c = 0;
    while (!z.empty()) {
        ++c;
        auto v = z.back(); z.pop_back();
        for (auto v2 : adj[v])
            if (--indeg[v2] == 0)
                z.push_back(v2);
    }

    if (c == n) {
        cout << "1\n";
        for (int i = 0; i < m; ++i)
            cout << "1 ";
    } else {
        cout << "2\n";
        for (auto [a, b] : e)
            cout << (1 + (a > b)) << ' ';
    }
    cout << '\n';

    return 0;
}