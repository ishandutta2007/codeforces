#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int MOD = 998244353;
int mod(int n) {
    if (n < 0) {
        return n % MOD + MOD;
    }   
    else {
        if (n < MOD) return n;
        else if (n < 2 * MOD) return n - MOD;
        else return n % MOD;
    }   
}           
void add(int &a, int b) {
    a = mod(a + b);
}
vector <int> g[N];
int ans[N], sum[N], good[N];
int _ans[3], __ans[3];
int _sum[3], __sum[3];
void dfs(int u) {
    if (g[u].empty()) {
        ans[u] = sum[u] = good[u] = 1;
        return;
    }
    for (int v : g[u]) {
        dfs(v);
    }   
    for (int i = 0; i < 3; ++i) _ans[i] = _sum[i] = 0;
    _ans[0] = 1;
    for (int v : g[u]) {
        for (int i = 0; i < 3; ++i) __sum[i] = 0;
        for (int i = 0; i < 3; ++i) {
            add(__sum[i], _sum[i] * ans[v] + sum[v] * _ans[i]);
            if (i == 0) {
                add(__sum[min(2ll, i + 1)], _sum[i] * good[v] + sum[v] * _ans[i]);
            }   
            else {
                add(__sum[min(2ll, i + 1)], _sum[i] * good[v] + sum[v] * _ans[i] - good[v] * _ans[i]);
            }   
        }   
        for (int i = 0; i < 3; ++i) _sum[i] = __sum[i];
        for (int i = 0; i < 3; ++i) __ans[i] = 0;
        for (int i = 0; i < 3; ++i) {
            add(__ans[i], _ans[i] * ans[v]);
            add(__ans[min(2ll, i + 1)], _ans[i] * good[v]);
        }   
        for (int i = 0; i < 3; ++i) _ans[i] = __ans[i];
    }   
    ans[u] = mod(_ans[0] + _ans[2]);
    sum[u] = mod(_sum[0] + _sum[2]);
    good[u] = _ans[2];
    int add = 0;
    int cnt = 1;
    for (int v : g[u]) {
        add = mod(add * ans[v] + good[v] * cnt);
        cnt = mod(cnt * ans[v]);
    }   
    good[u] = mod(good[u] + add);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif  
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }   
    dfs(1);
    cout << ans[1] << '\n';    
}