#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1000000007;
int n, x, ans, dp[1 << 20], deg2[1 << 20];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    deg2[0] = 1;
    for (int i = 1; i < (1 << 20); ++i)
        deg2[i] = deg2[i - 1] * 2 % MOD;
    cin >> n;
    while (n--)
        cin >> x, ++dp[x];
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < (1 << 20); ++j)
            if ((j >> i) & 1)
                add(dp[j ^ (1 << i)], dp[j]);
    for (int i = 0; i < (1 << 20); ++i)
        add(ans, (__builtin_popcount(i) % 2 == 0 ? deg2[dp[i]] : MOD - deg2[dp[i]]));
    cout << ans;
}