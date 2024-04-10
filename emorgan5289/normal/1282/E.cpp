#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        ll n; fin >> n;
        vector<array<ll, 3>> v(n-2), e(n-2);
        unordered_map<ll, array<ll, 2>> m;

        for (auto& x : v) {
            fin >> x[0] >> x[1] >> x[2];
            x[0]--; x[1]--; x[2]--;
        }

        for (ll i = 0; i < n-2; i++) {

            ll a = max(v[i][2], v[i][1]) * 10000000 + min(v[i][2], v[i][1]);
            ll b = max(v[i][0], v[i][2]) * 10000000 + min(v[i][0], v[i][2]);
            ll c = max(v[i][0], v[i][1]) * 10000000 + min(v[i][0], v[i][1]);

            e[i][0] = a; e[i][1] = b; e[i][2] = c;

            if (m.count(a)) m[a][1] = i;
            else m[a] = {i, -1};
            if (m.count(b)) m[b][1] = i;
            else m[b] = {i, -1};
            if (m.count(c)) m[c][1] = i;
            else m[c] = {i, -1};
        }

        vector<ll> q, stack = {0};
        vector<bool> visited(n-2, 0);
        visited[0] = 1;

        while (!stack.empty()) {
            ll i = stack.back(); stack.pop_back();
            q.push_back(i);
            for (ll x : e[i]) {
                auto d = m[x];
                if (d[1] == -1) continue;
                ll j = d[0]+d[1]-i;
                if (!visited[j]) {
                    visited[j] = 1;
                    stack.push_back(j);
                }
            }
        }
        reverse(all(q));

        vector<vector<ll>> adj(n);
        for (ll i = 0; i < n-2; i++) {
            if (m[e[i][0]][1] == -1) {
                adj[v[i][1]].push_back(v[i][2]);
                adj[v[i][2]].push_back(v[i][1]);
            }
            if (m[e[i][1]][1] == -1) {
                adj[v[i][0]].push_back(v[i][2]);
                adj[v[i][2]].push_back(v[i][0]);
            }
            if (m[e[i][2]][1] == -1) {
                adj[v[i][1]].push_back(v[i][0]);
                adj[v[i][0]].push_back(v[i][1]);
            }
        }

        vector<ll> p = {adj[0][0], 0};
        for (ll i = 0; i < n-2; i++)
            p.push_back(adj[p.back()][0]+adj[p.back()][1]-p[p.size()-2]);

        for (auto& x : p) cout << x+1 << " "; cout << "\n";
        for (auto& x : q) cout << x+1 << " "; cout << "\n";
    }
}