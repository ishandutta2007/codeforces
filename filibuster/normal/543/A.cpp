#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;

const int N = 500 + 13;

/*
*/

int M = 1e9 + 7;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        return res - M;
    else
        return res;
}

int a[N];
int dp1[N][N], dp2[N][N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n, m, b;
    cin >> n >> m >> b >> M;


    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp1[0][0] = 1;
    dp2[0][0] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int l = 0; l <= b; l++) {
                dp2[j][l] = dp1[j][l];//(i > 0 ? dp1[j][l] : 0);
                if(j > 0 && l >= a[i]) {
                    dp2[j][l] = sum(dp2[j][l],
                                    dp2[j - 1][l - a[i]]);
                }
//                cout << i << ' '<< j << ' ' << l << ' ' << dp2[j][l] << endl;

            }

        }

//        for(int l = 0; l <= b; l++) {
//            ans = sum(ans, dp2[m][l]);
//        }

        for(int j = 0; j <= m; j++) {
            for(int l = 0; l <= b; l++) {
                dp1[j][l] = dp2[j][l];
                dp2[j][l] = 0;
            }
        }
    }
//
    for(int i = 0; i <= b; i++)
        ans = sum(ans, dp1[m][i]);
//    for(int i = 0; i < n; i++) {
//        for(int l = 0; l <= b; l++)
//            ans = sum(ans, dp[i][m][l]);
//    }

    cout << ans;
}