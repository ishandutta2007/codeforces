#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int, vector<int>> m;
    int q; cin >> q;
    int k = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            m[x].pb(k++);
        } else {
            int x, y; cin >> x >> y;
            if (x == y) continue;
            if (m[y].size() < m[x].size())
                swap(m[x], m[y]);
            for (int i : m[x]) m[y].pb(i);
            m[x].clear();
        }
    }
    vector<int> ans(k);
    for (auto& [x, v] : m)
        for (int i : v)
            ans[i] = x;
    for (int i = 0; i < k; i++)
        cout << ans[i] << " \n"[i == k-1];
}