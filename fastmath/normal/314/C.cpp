#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int dp[MAXN];
int f[MAXN];

void upd(int i, int x) {
    int delt = mod(x - dp[i]);
    dp[i] = x;
    for (; i < MAXN; i |= (i + 1)) {
        f[i] = mod(f[i] + delt);
    }   
}

int get(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f[i];
    }   
    return ans;
}

void solve() {
    upd(0, 1);
    for (int i = 0; i < n; ++i) {
        int t = get(a[i]);
        upd(a[i], mod(t * a[i]));
    }
}

void print() {
    int ans = 0;
    for (int i = 1; i < MAXN; ++i) ans = mod(ans + dp[i]);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}