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

void removeparents(vector<vector<int>>& adj, int root) {

    vector<int> stack = {root};
    while (!stack.empty()) {
        int i = stack.back();
        stack.pop_back();
        for (int j : adj[i]) {
            stack.push_back(j);
            adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
        }
    }
}

vector<vector<int>> adj;
vector<int> dp;
int out = -1;

void dfs(int r) {
    vector<int> v;
    for (int i : adj[r]) {
        dfs(i);
        v.pb(dp[i]);
    }
    sort(all(v), greater<int>());
    int x = (r == 0 ? -1 : 0)+adj[r].size()+(v.size() > 0 ? v[0] : 1)+(v.size() > 1 ? v[1] : 1);
    out = max(out, x);
    dp[r] = adj[r].size()+(v.size() > 0 ? v[0] : 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        adj.assign(n, {});
        for (int i = 0; i < n-1; i++) {
            int x, y; fin >> x >> y;
            adj[x-1].pb(y-1);
            adj[y-1].pb(x-1);
        }
        dp.assign(n, 0);
        removeparents(adj, 0);
        out = 0;
        dfs(0);
        debug(dp);
        cout << out << "\n";
    }
}