#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];
int dp[N][7][2];

/*
5 10
99.99

1
5 4 1
1 5 4 3 2
*/

void solve() {
    int n, k, z;
    cin >> n >> k >> z;

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= z; j++) {
            for(int l = 0; l < 2; l++)
                dp[i][j][l] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = a[0];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= z; j++) {
            for(int l = 0; l < 2; l++) {
//                cout << i << ' ' << j << ' ' <<l << ' ' << dp[i][j][l] << endl;
                dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][l] + a[i - j * 2 + 1]);
                if(l == 0 && i - j * 2 > 0 && j < z) {
                    dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][l] + a[i - j * 2 - 1]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= z; j++)
        for(int l = 0; l < 2; l++)
            ans = max(ans, dp[k][j][l]);

    cout << ans << endl;
}

//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}