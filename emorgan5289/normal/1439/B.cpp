#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
vector<int> adj[N];
int deg[N], v[N], on[N];

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        deg[i] = 0;
        v[i] = 0, on[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
        deg[x]++, deg[y]++;
    }
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
        s.insert({deg[i], i});
    int t = 0;
    vector<vector<int>> grp(n), clq(n);
    while (!s.empty()) {
        auto [d, i] = *s.begin();
        if (d >= k) {
            cout << "1 " << s.size() << "\n";
            for (auto& [_, j] : s)
                cout << j+1 << " ";
            cout << "\n";
            return;
        }
        if (d == k-1) {
            // O(m/k)
            vector<int> b = {i};
            for (int j : adj[i])
                if (on[j]) b.pb(j);

            for (int j : b) {
                grp[j].pb(t);
                clq[t].pb(j);
            }
            t++;
        }
        for (int j : adj[i]) {
            if (on[j]) {
                s.erase(s.find({deg[j], j}));
                deg[j]--;
                s.insert({deg[j], j});
            }
        }
        on[i] = 0;
        s.erase(s.find({deg[i], i}));
    }
    vector<int> cnt(t);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i])
            v[j] = 1;
        for (int c : grp[i])
            for (int j : clq[c])
                if (v[j]) cnt[c]++;
        for (int j : adj[i])
            v[j] = 0;
    }
    for (int i = 0; i < t; i++)
        if (cnt[i] == k*(k-1)) {
            cout << "2\n";
            for (int j : clq[i])
                cout << j+1 << " ";
            cout << "\n";
            return;
        }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}