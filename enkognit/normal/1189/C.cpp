#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, i, j, k1, k0, a[100001];
pll dp[100001][20];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i][0]=mp(a[i],0);
        for (int j = 2, o = 1; j <= i && o < 20; j*=2, o++)
        {
            ll p=(dp[i-j/2][o-1].fi+dp[i][o-1].fi);
            //cout << i << " " << o << " " << p << " ";
            if (p>9) p=1; else p=0;
            dp[i][o]=mp((dp[i-j/2][o-1].fi+dp[i][o-1].fi)%10,
                        dp[i-j/2][o-1].se+dp[i][o-1].se+p);
            //cout << dp[i][o].se << "\n";
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll o=y-x+1,z=0;
        while (o>1) o/=2,z++;
        cout << dp[y][z].se << "\n";
    }
    return 0;
}