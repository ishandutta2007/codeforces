#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

const int N = 1e6 + 7;

int dp[N][2][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    dp[1][1][1] = 1;
    dp[1][0][0] = 1;
    dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = dp[0][1][1] = 1;
    for (int i = 2; i < N; ++i) { 
        for (int k = 0; k <= 1; ++k) {
            for (int j = 0; j <= 1; ++j) {
                if (i % 2 == 1) {
                    int x = i / 2;
                    if (x % 2 != (j ^ k)) continue;
                    add(dp[i][k][j], mul(dp[i / 2][k][j ^ 1], dp[i / 2][((x + 1) % 2) ^ k][j]));
                } else {
                    int x = i / 2 - 1;
                    if (x % 2 == (j ^ k)) {
                        add(dp[i][k][j], mul(dp[i / 2 - 1][k][j ^ 1], dp[i / 2][((x + 1) % 2) ^ k][j]));
                    }
                    x = i / 2;
                    if (x % 2 == (j ^ k)) {
                        add(dp[i][k][j], mul(dp[i / 2][k][j ^ 1], dp[i / 2 - 1][((x + 1) % 2) ^ k][j]));
                    }
                }
            }
        }
    }
    int ans = 0;
    add(ans, dp[n][1][0]);
    add(ans, dp[n][1][1]);
    cout << ans << '\n';
}