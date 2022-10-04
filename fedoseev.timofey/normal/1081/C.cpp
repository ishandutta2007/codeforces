#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md =  998244353;

inline void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

inline int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> dp(n + 1, vector <int> (k + 1));
    dp[1][0] = m;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            add(dp[i][j], dp[i - 1][j]);
            if (j > 0) add(dp[i][j], mul(m - 1, dp[i - 1][j - 1]));
        }
    }
    cout << dp[n][k] << '\n';
}