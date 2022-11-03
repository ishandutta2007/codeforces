#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 14;

int a[N], b[N], c[N];
int dp[N][N];

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;

    int k = 0, m = 0;
//    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] == 1) {
            b[k++] = i;
        } else {
            c[m++] = i;
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++)
            dp[i][j] = INF;
    }

    dp[0][0] = 0;

    for(int i = 0; i < k; i++) {
        int mn = INF;
        for(int j = 0; j < m; j++) {
            mn = min(mn, dp[i][j]);
            dp[i + 1][j + 1] = mn + abs(b[i] - c[j]);//min();
        }
    }

    int ans = INF;
    for(int i = 0; i <= m; i++)
        ans = min(ans, dp[k][i]);

    cout << ans << endl;
}