#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[3005],m,b[3005];
int dp[305][305];

int f(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (!dp[i][j]) {
        dp[i][j] = max(f(i-1,j), f(i,j-1));
        if (abs(a[i] - b[j]) <= 1)
            dp[i][j] = max(dp[i][j], f(i-1,j-1) + 1);
        ++dp[i][j];
    }
    return dp[i][j]-1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b,b+m);
    cout << f(n-1,m-1);

    return 0;
}