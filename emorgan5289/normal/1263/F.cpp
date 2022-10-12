#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<vector<int>> readgraph() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int j; cin >> j, j--;
        adj[j].pb(i);
    }
    return adj;
}

void dfs(vector<vector<int>>& adj, vector<int>& l, vector<int>& r, int i) {
    if (adj[i].size() > 0) l[i] = inf, r[i] = -inf;
    for (auto& j : adj[i]) {
        dfs(adj, l, r, j);
        l[i] = min(l[i], l[j]), r[i] = max(r[i], r[j]);
    }
}

const int N = 2005;
int c1[N][N], c2[N][N], dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x; cin >> n;
    auto a = readgraph();
    vector<int> la(a.size()), ra(a.size());
    for (int i = 0; i < n; i++)
        cin >> x, la[x-1] = ra[x-1] = i;
    auto b = readgraph();
    vector<int> lb(b.size()), rb(b.size());
    for (int i = 0; i < n; i++)
        cin >> x, lb[x-1] = rb[x-1] = i;
    dfs(a, la, ra, 0), dfs(b, lb, rb, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < a.size(); j++)
            if (la[j] >= i) c1[i][ra[j]]++;
        for (int j = 1; j < b.size(); j++)
            if (lb[j] >= i) c2[i][rb[j]]++;
        for (int j = i; j < n; j++) {
            c1[i][j] += c1[i][j-1];
            c2[i][j] += c2[i][j-1];
        }
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], dp[j]+max(c1[j][i-1], c2[j][i-1]));
    cout << dp[n] << "\n";
}