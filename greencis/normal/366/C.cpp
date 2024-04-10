#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,a[105],b,c,zero;
int dp[105][200105];

int main()
{
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 200105; ++j)
            dp[i][j] = -1;
    dp[0][100020] = 0;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b;
        c = a[i] - k * b;
        for (int j = 0; j < 200105; ++j)
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        for (int j = max(-c, 0); j + c < 200105; ++j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j + c] = max(dp[i + 1][j + c], dp[i][j] + a[i]);
        }
    }

    cout << (dp[n][100020] ? dp[n][100020] : -1);

    return 0;
}