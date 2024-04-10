#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
// #define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define ms1(dp) memset(dp, -1, sizeof(dp));
#define ms0(dp) memset(dp, 0, sizeof(dp));
#define setbits(x) __builtin_popcountll(x) //count number of 1
#define zrobits(x) __builitin_ctzll(x)     //count number of zero before 1st 1 ex- (110000)2 ->4
#define MOD 1000000007
#define INF 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) x.begin(), x.end()
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

int k, nf, mf;

int arr[71][71];
int dp[71][71][71][71];

int funt(int n, int m, int cnt, int mo)
{
    if (n == 0 && mo==0)
        return 0;
    if (n == 0)
        return -(71*71*71);
    if (m == 0)
        return (funt(n - 1, mf, mf/2, mo));
    if(cnt==0)
        return (funt(n - 1, mf, mf/2, mo));
    if (dp[n][m][cnt][mo] != -1)
        return dp[n][m][cnt][mo];
    return dp[n][m][cnt][mo] = max(funt(n, m - 1, cnt, mo), arr[n - 1][m - 1] + funt(n, m - 1, cnt - 1, (mo + 71 * k - arr[n - 1][m - 1]) % k));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ms1(dp);
    cin >> nf >> mf >> k;

    FOR(i, 0, nf - 1)
    FOR(j, 0, mf - 1)
    cin >>
        arr[i][j];

    cout << funt(nf, mf, mf / 2, 0);
}