#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int N = 50 + 13;
const int M = 2e4 + 13;
/*

abs(k - i)
k, k - 1, k - 2, k - 3,..., 1, 0, 1, 2, 3,..., k - 1
*/



/*
1
2 1 1
1 0


1
4 3 4
0 2 4 3

3 2 2
1 2 3
4 5 6

*/

int dp[N][M];
int a[N][M];
int s[N][M];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    {
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += a[0][i];
        }
        for(int i = 0; i + k <= m; i++) {
            dp[0][i] = sum;
            sum -= a[0][i];
            sum += a[0][i + k];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = s[i][j - 1] + a[i][j - 1];
        }
    }

    for(int i = 1; i < n; i++) {
//        cout << i << endl;
        multiset<int> ms;
        for(int j = k; j + k <= m; j++) {
            ms.insert(dp[i - 1][j] + s[i][j + k] - s[i][j]);
        }

        for(int j = 0; j + k <= m; j++) {
//            cout << "j " << j << endl;
            if(j >= k) {
                ms.insert(dp[i - 1][j - k] + s[i][j] - s[i][j - k]);
            }
//            for(auto x : ms)
//                cout << x << ' ';
//            cout << endl;
//            if(j + 2 * k <= m) {
////                cout << dp[i - 1][j + k] + s[i][j + 2 * k] - s[i][j + k] << endl;
//                ms.erase(ms.find(dp[i - 1][j + k] + s[i][j + 2 * k] - s[i][j + k]));
//            }


            dp[i][j] = s[i][j + k] - s[i][j] + (ms.empty() ? 0 : *ms.rbegin());
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            for(int l = max(0, j - k + 1); l < j + k; l++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][l] + s[i][l + k] - s[i][l] + s[i][j + k] - s[i][j] +
                               s[i][max(l, j)] - s[i][min(l, j) + k]);
//                cout << i << ' ' << j << ' ' << l << ' ' <<
//                dp[i - 1][l] + s[i][l + k] - s[i][l] + s[i][j + k] - s[i][j] +
//                               s[i][max(l, j)] - s[i][min(l, j) + k] <<
//                               ' ' << dp[i - 1][l] << ' ' << s[i][l + k] - s[i][l]
//                               << ' ' << s[i][j + k] - s[i][j] << ' ' << -
//                               s[i][max(l, j) + 1] + s[i][min(l, j)]<< endl;

            }

            if(j + 2 * k <= m) {
//                cout << dp[i - 1][j + k] + s[i][j + 2 * k] - s[i][j + k] << endl;
                ms.erase(ms.find(dp[i - 1][j + k] + s[i][j + 2 * k] - s[i][j + k]));
            }

        }
//        return 0;
//        cout << endl << endl;
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

//    for(int i = 0; i < n; i++) {
//        cout << "i " << i << endl;
//        for(int j = 0; j + k <= m; j++)
//            cout << dp[i][j] << ' ';
//        cout << endl;
//        cout << endl;
//    }

    cout << ans << endl;
}