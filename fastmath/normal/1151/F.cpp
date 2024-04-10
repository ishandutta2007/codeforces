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
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    if (n < 0) {
        if (n + MOD >= 0) return n + MOD;
        else return (n % MOD + MOD) % MOD;
    }   
    else {
        if (n < MOD) return n;
        else if (n < (MOD << 1)) return n - MOD;
        else return n % MOD;
    }   
}
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1 << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }
    return ans;
}   
int dv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
const int N = 101;
int m[N][N], ans[N][N], t[N][N];
void add(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            t[i][j] = 0;
        }   
    }   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!a[i][k] || !b[k][j]) continue;
                t[i][j] = mod(t[i][j] + a[i][k] * b[k][j]);
            }   
        }   
    }   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = t[i][j];
        }   
    }   
}   
void pw(int p) {
    for (int i = 0; i < N; ++i) ans[i][i] = 1;
    for (int i = 0; (1 << i) <= p; ++i) {
        if ((p >> i) & 1) add(ans, m);
        add(m, m);
    }   
}   
bool a[N];
int cnt[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int l = cnt[0];
    int r = n - l;
    int op = n * (n - 1) / 2;
    for (int l1 = 0; l1 <= cnt[0] && l1 <= cnt[1]; ++l1) {
        int l0 = l - l1;
        int r0 = cnt[0] - l0;
        int r1 = cnt[1] - l1;
        m[l1][l1] = op;
        if (l1) {
            m[l1][l1 - 1] = mod(l1 * r0);
            m[l1][l1] = mod(m[l1][l1] - m[l1][l1 - 1]);
        }
        m[l1][l1 + 1] = mod(l0 * r1);
        m[l1][l1] = mod(m[l1][l1] - m[l1][l1 + 1]);
    }   
    pw(k);
    int sum = 0;
    for (int i = 0; i < l; ++i) sum += a[i];
    cout << dv(ans[sum][0], fp(op, k)) << '\n';
}