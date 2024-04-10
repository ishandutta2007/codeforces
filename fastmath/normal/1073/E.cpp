#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
const int N = 10;
const int LEN = 20;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int dp[LEN][1 << N];
int sum[LEN][1 << N];
int dp1[1 << N][LEN][N + 1];
int sum1[1 << N][LEN][N + 1];

void prec() {
    dp[0][0] = 1;
    for (int i = 0; i < LEN - 1; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int c = 0; c <= 9; ++c) {
                dp[i + 1][mask | (1 << c)] = mod(dp[i + 1][mask | (1 << c)] + dp[i][mask]);
                sum[i + 1][mask | (1 << c)] = mod(sum[i + 1][mask | (1 << c)] + sum[i][mask] * 10 + dp[i][mask] * c);
            }
        }
    }   
    for (int m = 0; m < (1 << N); ++m) {
        for (int len = 0; len < LEN; ++len) {
            for (int mask = 0; mask < (1 << N); ++mask) {
                int cnt = __builtin_popcount(m | mask);
                dp1[m][len][cnt] = mod(dp1[m][len][cnt] + dp[len][mask]);
                sum1[m][len][cnt] = mod(sum1[m][len][cnt] + sum[len][mask]);
            }   
        }
    }   
}

int l, r, k;
void read() {
    cin >> l >> r >> k;
}

int get_(int len) {
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        for (int c = 1; c <= 9; ++c) {
            int add = c;
            for (int t = 0; t < len - i - 1; ++t) add = mod(add * 10);
            for (int t = 0; t <= k; ++t) {
                ans = mod(ans + sum1[1 << c][len - i - 1][t]);
                ans = mod(ans + add * dp1[1 << c][len - i - 1][t]);
            }   
        }
    }
    return ans;
}

int get(int n) {
    int ans = 0;
    string s = to_string(n);

    ans = get_(s.size() - 1);

    int curr = 0;
    int val = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int c = s[i] - '0';
        for (int nc = (!i); nc < c; ++nc) {
            int tmp = curr | (1 << nc);
            int ost = s.size() - i - 1;
            int pref = mod(val * 10 + nc);
            for (int t = 0; t < ost; ++t) pref = mod(pref * 10);
            for (int t = 0; t <= k; ++t) {
                ans = mod(ans + pref * dp1[tmp][ost][t]);
                ans = mod(ans + sum1[tmp][ost][t]);
            }
        }
        curr |= (1 << c);
        val = mod(val * 10 + c);
    }
    return ans;
}

int ans = 0;
void solve() {
    ans = mod(get(r + 1) - get(l));
}

void print() {
    cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();
    read();
    solve();
    print();

    return 0;
}