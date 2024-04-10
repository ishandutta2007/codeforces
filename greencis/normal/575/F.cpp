#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n,x,a[5005],b[5005];
int pos[10005];
ll dp[2][10005];
ll curdp,suffmin[10005],prefmin[10005];

int main()
{
    scanf("%d%d",&n,&x);
    pos[0] = x;
    for (int i = 0; i < n; ++i) scanf("%d%d",&a[i],&b[i]), pos[i*2 + 1] = a[i], pos[i*2 + 2] = b[i];
    sort(pos, pos+n+n+1);
    //for (int i = 0; i < n+n+1; ++i) dp[0][i] = abs(x - pos[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = n+n; j >= 0; --j) {
            curdp = dp[0][j] + (ll)abs(pos[j] - pos[0]);
            if (j == n + n) suffmin[j] = curdp;
            else suffmin[j] = min(curdp, suffmin[j + 1]);
        }

        for (int j = 0; j < n+n+1; ++j) {
            curdp = dp[0][j] + (ll)abs(pos[j] - pos[n+n]);
            if (j == 0) prefmin[j] = curdp;
            else prefmin[j] = min(prefmin[j-1], curdp);
        }

        for (int j = 0; j < n+n+1; ++j) {
            if (i != 0)
                dp[1][j] = min(prefmin[j] - (ll)abs(pos[j] - pos[n+n]), suffmin[j] - (ll)abs(pos[j] - pos[0]));
            else
                dp[1][j] = abs(x - pos[j]);
            if (pos[j] < a[i] || pos[j] > b[i])
                dp[1][j] += min((ll)abs(pos[j] - a[i]), (ll)abs(pos[j] - b[i]));
        }

        for (int j = 0; j < n+n+1; ++j) dp[0][j] = dp[1][j], dp[1][j] = 0;
    }
    ll ans = 9e18;
    for (int i = 0; i < n+n+1; ++i) ans = min(ans, dp[0][i]);
    cout << ans;

    return 0;
}