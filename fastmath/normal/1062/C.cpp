#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1e5 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int n, q;
int a[MAXN];
int pref[MAXN][2];

int pw[MAXN];

int get(int l, int r) {
    int cnt0 = pref[r + 1][0] - pref[l][0];
    int cnt1 = pref[r + 1][1] - pref[l][1];
    int sum1 = pw[cnt1] - 1;
    int sum2 = mod(sum1 * (pw[cnt0] - 1));
    return mod(sum1 + sum2);
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) pw[i] = mod(pw[i - 1] << 1);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }   

    for (int i = 0; i < n; ++i) {
        pref[i + 1][a[i]] = pref[i][a[i]] + 1;
        pref[i + 1][a[i] ^ 1] = pref[i][a[i] ^ 1];
    }   

    for (int i = 0; i < q; ++i) {
         int l, r;
         cin >> l >> r;
         --l; --r;
         cout << get(l, r) << '\n';
    }   

    return 0;
}