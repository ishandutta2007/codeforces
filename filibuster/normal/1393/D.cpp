#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2000 + 13;


/*
1
3
1 1 1
*/

int n, m;
string a[N];
int dp[2][N][N];
int up[N][N], dw[N][N];

void calc(int l) {
    for(int i = 0; i < n; i++) {
        dp[l][i][0] = 1;
        for(int j = 0; j < m; j++) {
            up[i][j] = dw[i][j] = 1;
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            up[i][j] = (a[i][j] == a[i - 1][j] ? up[i - 1][j] : 0) + 1;
        }

        for(int i = n - 2; i >= 0; i--) {
            dw[i][j] = (a[i][j] == a[i + 1][j] ? dw[i + 1][j] : 0) + 1;
        }
    }
//
//    cout << "l :  " << l << endl;
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << i << ' '<< j << ' ' << up[i][j] << ' ' << dw[i][j] << endl;
//        }
//    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[l][i][j] = (a[i][j - 1] == a[i][j] ? min(min(up[i][j], dw[i][j]), dp[l][i][j - 1] + 1) : 1);
        }
    }

//    cout << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    calc(0);

    for(int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
    }

    calc(1);
    for(int i = 0; i < n; i++) {
        reverse(dp[1][i], dp[1][i] + m);
    }

    li ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
//            cout << i << ' ' << j << ' ' << dp[0][i][j] << ' ' << dp[1][i][j] << endl;
            ans += min(dp[0][i][j], dp[1][i][j]);
        }
    }

    cout << ans << endl;
}