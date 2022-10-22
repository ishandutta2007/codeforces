#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2007;
vector <int> sb[N], g[N];
int p[N], c[N];
int ans[N];

bool comp(int u, int v) {
    return ans[u] < ans[v];
}   

void dfs(int u) {
    sb[u].app(u);
    for (int v : g[u]) {
        dfs(v);
        for (int e : sb[v])
            sb[u].app(e);
    }   
    if (c[u] >= sb[u].size()) {
        cout << "NO\n";
        exit(0);
    }   
    ans[u] = c[u] + 1;
    int cur = 0;
    for (int v : g[u]) {
        if (cur + sb[v].size() <= c[u]) {
            for (int e : sb[v]) 
                ans[e] += cur;
        }   
        else if (cur >= c[u]) {
            for (int e : sb[v]) 
                ans[e] += cur + 1;
        }   
        else {
            for (int i = 0; i < c[u] - cur; ++i) {
                ans[sb[v][i]] += cur;
            }   
            for (int i = c[u] - cur; i < sb[v].size(); ++i) {
                ans[sb[v][i]] += cur + 1;
            }   
        }   
        cur += sb[v].size();
    }   
    sort(all(sb[u]), comp);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i];
        g[p[i]].app(i);
        if (!p[i])
            root = i;
    }
    dfs(root);
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}