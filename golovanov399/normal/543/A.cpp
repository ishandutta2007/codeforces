#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, m, b, mod;
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<vector<int> > dp(m + 1, vector<int>(b + 1, 0)), dp1(m + 1, vector<int>(b + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= m; j++){
            for (int ij = 0; ij <= b; ij++){
                dp1[j][ij] = dp[j][ij];
                if (ij >= a[i] && j > 0)
                    dp1[j][ij] += dp1[j - 1][ij - a[i]];
                dp1[j][ij] %= mod;
            }
        }
        dp1.swap(dp);

        // for (int j = 0; j <= m; j++){
        //  for (int ij = 0; ij <= b; ij++){
        //      cerr << dp[j][ij] << " ";
        //  }
        //  cerr << "\n";
        // }
        // cerr << "\n";
    }

    int s = 0;
    for (int i = 0; i <= b; i++)
        s = (s + dp[m][i]) % mod;
    printf("%d\n", s);

    return 0;
}