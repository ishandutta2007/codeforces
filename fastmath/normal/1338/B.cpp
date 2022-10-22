#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 5e5 + 7;
int n;
vector <int> g[N];
int cnt_leaf[2], h[N], ansr = 0;
void dfs(int u, int p) {
    if (g[u].size() == 1) {
        ++cnt_leaf[h[u] & 1];
    }

    int leaf = 0, child = 0;
    for (int v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
            leaf += g[v].size() == 1;
            ++child;
        }   
    }   
    ansr += child - max(0ll, leaf - 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 1) 
            root = i;
    }   
    dfs(root, root);



    if (cnt_leaf[0] && cnt_leaf[1])
        cout << 3 << ' ';
    else
        cout << 1 << ' ';
    cout << ansr << endl;
}