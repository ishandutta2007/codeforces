#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

vector<vector<int>> adj;
vector<ll> d, s;

void dfs(int i, int p) {
    d[i] = d[p]+1;
    s[i] = 0;
    for (int j : adj[i])
        if (j != p) {
            dfs(j, i);
            s[i] += s[j]+1;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; fin >> n >> k;
    adj.assign(n, {});
    d.assign(n, -1);
    s.assign(n, -1);
    for (int i = 0; i < n-1; i++) {
        int u, v; fin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        d[i] -= s[i];
    sort(all(d), greater<int>());
    ll out = 0;
    for (int i = 0; i < k; i++)
        out += d[i];
    cout << out << "\n";
}