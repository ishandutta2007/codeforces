#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int n;
int a[N], f[N], fr[N], p[N];
bool comp(int i, int j) {
    return a[i] < a[j];
}   
void add(int *f, int i, int x) {
    for (; i < N; i |= (i + 1)) f[i] = mod(f[i] + x);
}   
int get(int *f, int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans = mod(ans + f[i]);
    return ans;
}   
int gett(int i) {
    return mod(get(f, i - 1) * (n - i) + get(fr, n - i - 2) * (i + 1) + (n - i) * (i + 1));
}
void add(int i) {
    add(f, i, i + 1);
    add(fr, n - i - 1, n - i);
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = i;
    }   
    sort(p, p + n, comp);
    int ans = 0;
    for (int t = 0; t < n; ++t) {
        int i = p[t];
        ans = mod(ans + gett(i) * a[i]);
        add(i);
    }       
    cout << ans << '\n';
}