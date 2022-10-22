#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
const int N = 1e6 + 7;
int n;
int a[N];
void add(int *f, int i) {
    for (; i < N; i |= (i + 1)) ++f[i];
}   
void del(int *f, int i) {
    for (; i < N; i |= (i + 1)) --f[i];
}   
int get(int *f, int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans += f[i];
    return ans;
}   
void add_rev(int *f, int i) {
    i = N - i - 1;
    for (; i < N; i |= (i + 1)) ++f[i];
}   
int get_rev(int *f, int i) {
    i = N - i - 1;
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans += f[i];
    return ans;
}   
int fc[N];
int f[N];
int get() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = mod(ans + get_rev(f, a[i] + 1));
        add_rev(f, a[i]);
    }   
    return ans;
}   
int sum(int n) {
    return mod(n * (n + 1) / 2);
}   
int flr[N], fr[N];
int cur = 0, l = 0;
void upd(int x) {
    int lb = get_rev(flr, x + 1);
    int rm = get(fr, x - 1);
    cur = mod(cur - lb);
    l = mod(l + lb);
    cur = mod(cur + rm);
    add_rev(flr, x);
    del(fr, x);
}   
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }   
    return ans;
}   
int DV = fp(2, MOD - 2);
int div2(int n) {
    return mod(n * DV);
}
int getall(int n) {
    return mod(mod(n * (n - 1) / 2) * div2(fc[n]));
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    fc[0] = 1;
    for (int i = 1; i < N; ++i) fc[i] = mod(fc[i - 1] * i);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    for (int i = 1; i <= n; ++i) {
        add(fr, i);
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int in_r = n - i;
        int can = get(fr, a[i] - 1);
        int cnt = mod(can * fc[in_r - 1]);
        ans = mod(ans + (cur + l) * cnt);
        ans = mod(ans + fc[in_r - 1] * sum(can - 1));
        ans = mod(ans + can * getall(in_r - 1));
        upd(a[i]);
    }   
    ans = mod(ans + get());
    cout << ans << '\n';
}