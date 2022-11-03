#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
5 4
1 2 1 3
6 2 1 5 7

*/

vector<int> g[N];
int a[N];

vector<li> dfs(int v, int l, int r) {
//    cout << "dfs " << v << ' ' << l << ' ' << r << endl;
    if(g[v].empty()) {
        vector<li> res(r - l + 1);
        for(int i = 0; i < res.size(); i++)
            res[i] = (i + l) * 1ll * a[v];
//        cout << "res " << v << "  : " << endl;
//        for(auto x : res)
//            cout << x << ' ';
//        cout << endl;
        return res;
    }

    int lf = l / g[v].size(), rg = (r + g[v].size() - 1) / g[v].size();

    vector<vector<li>> dp(g[v].size());
    for(int i = 0; i < g[v].size(); i++) {
        dp[i] = dfs(g[v][i], lf, rg);
    }

    vector<li> res(r - l + 1, 0);
    for(int i = 0; i <= r - l; i++) {
        res[i] = (l + i) * 1ll * a[v];
        int q = (l + i) / g[v].size(), r = (l + i) % g[v].size();
//        cout << "q r " << q << ' ' << r << endl;
        vector<li> bst(g[v].size());
        for(int j = 0; j < g[v].size(); j++) {
            res[i] += dp[j][q - lf];
            bst[j] = dp[j][q - lf + 1] - dp[j][q - lf];
        }

        sort(bst.rbegin(), bst.rend());

        for(int j = 0; j < r; j++)
            res[i] += bst[j];
    }

//    cout << "res " << v << "  : " << endl;
//    for(auto x : res)
//        cout << x << ' ';
//    cout << endl;

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        p--;

        g[p].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto res = dfs(0, k, k);
    cout << res[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}