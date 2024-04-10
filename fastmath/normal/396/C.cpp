#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int n, q;
vector <int> g[N];
int l[N], r[N];
int ptr = 0;
int h[N];
void dfs(int u, int d) {
    h[u] = d;
    l[u] = ++ptr;
    for (int v : g[u]) dfs(v, d + 1);
    r[u] = ptr;
}   
int f1[N], f2[N];
void add(int f[], int i, int x) {
    for (; i < N; i |= (i + 1)) {
        f[i] = mod(f[i] + x);
    }   
}   
void add(int f[], int l, int r, int x) {
    add(f, l, x);
    add(f, r + 1, -x);
}   
void add(int v, int x, int k) {
    add(f1, l[v], r[v], mod(x + k * h[v]));
    add(f2, l[v], r[v], k);
}   
int get(int f[], int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans = mod(ans + f[i]);
    }   
    return ans;
}   
int get(int v) {
    return mod(get(f1, l[v]) - get(f2, l[v]) * h[v]);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        g[p].push_back(i);
    }   
    dfs(0, 0);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            --v;
            add(v, x, k);
        }
        else {
            int v;
            cin >> v;
            --v;
            cout << get(v) << '\n';
        }   
    }   
}