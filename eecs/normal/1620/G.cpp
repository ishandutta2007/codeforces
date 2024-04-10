#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n, ind[1 << 23];
short mn[1 << 23][26], cnt[23][26];
long long sum[1 << 23];
string s[23];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char ch : s[i]) cnt[i][ch - 'a']++;
    }
    fill(mn[0], mn[0] + 26, SHRT_MAX);
    for (int i = 1; i < 1 << n; i++) {
        int j = __builtin_ctz(i);
        sum[i] = 1;
        for (int c = 0; c < 26; c++) {
            mn[i][c] = min(cnt[j][c], mn[i ^ (1 << j)][c]);
            sum[i] = sum[i] * (mn[i][c] + 1) % P;
        }
        if (!__builtin_parity(i)) sum[i] = P - sum[i];
    }
    for (int i = 1; i < 1 << n; i <<= 1) {
        for (int j = 0; j < 1 << n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                sum[i + j + k] += sum[j + k];
            }
        }
    }
    long long xors = 0;
    for (int i = 1; i < 1 << n; i++) {
        int j = __builtin_ctz(i);
        ind[i] = ind[i ^ (1 << j)] + j + 1;
        xors ^= sum[i] % P * __builtin_popcount(i) * ind[i];
    }
    printf("%lld\n", xors);
    return 0;
}