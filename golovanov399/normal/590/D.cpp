#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int N = 155;

int dp[2][N][N * (N - 1) / 2];

int main(){

    int n = nxt(), k = nxt(), s = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    s = min(s, n * (n - 1) / 2);

    int cur = 0;
    for (int i = 0; i <= k; i++){
        for (int j = 0; j <= s; j++){
            dp[0][i][j] = dp[1][i][j] = INT_MAX;
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            for (int ij = 0; ij <= s; ij++){
                if (dp[cur][j][ij] != INT_MAX){
                    // cerr << i << ", " << j << ", " << ij << ": " << dp[cur][j][ij] << "\n";
                    dp[cur ^ 1][j][ij] = min(dp[cur ^ 1][j][ij], dp[cur][j][ij]);
                    // assert(ij + i - j >= 0);
                    dp[cur ^ 1][j + 1][ij + i - j] = min(dp[cur ^ 1][j + 1][ij + i - j], dp[cur][j][ij] + a[i]);
                    dp[cur][j][ij] = INT_MAX;
                }
            }
        }
        cur ^= 1;
    }

    int res = INT_MAX;
    for (int j = 0; j <= s; j++){
        res = min(res, dp[cur][k][j]);
    }
    cout << res << "\n";

    return 0;
}