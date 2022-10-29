#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=998244353;

ll n, m, k, c[35], dd[403][403][2][2], dp[2][403][403][3][3], pr1[1001], pr2[403][403];
vector<vector<ll> > a;
string s, d;

void solve()
{
    cin >> n;
    for (int i = 0; i < 26; i++)
    {
        cin >> c[i];
    }
    ll ans=1;
    for (int i = 1; i <= n; i++)
        if (i<=2) ans=(ans*26)%MOD; else ans=(ans*25)%MOD;
    for (int i = 0; i < 4; i++)
    {
        dd[2][(i&1)+((i&2)>0)][(i&1)][((i&2)>0)]=(i&1?1:25)*(((i&2)>0)?1:25);
    }
    for (int i = 2; i < n; i++)
        for (int j = 0; j <= n; j++)
            for (int u1 = 0; u1 < 2; u1++)
                for (int u2 = 0; u2 < 2; u2++)
                    if (dd[i][j][u1][u2])
    {
        //cout << i << " " << j << " " << u1 << " " << u2 << " " << dd[i][j][u1][u2] << "\n";
        if (u1==1)
        {
            dd[i+1][j][u2][0]=(dd[i+1][j][u2][0]+dd[i][j][u1][u2]*25)%MOD;
        }else
        {
            dd[i+1][j][u2][0]=(dd[i+1][j][u2][0]+dd[i][j][u1][u2]*24)%MOD;
            dd[i+1][j+1][u2][1]=(dd[i+1][j+1][u2][1]+dd[i][j][u1][u2])%MOD;
        }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            dp[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i==0?24:1)*(j==0?24:1);
        }

    for (int i = 2; i < n; i++)
    {
        ll o=min((ll)i/2+4, n);
        for (int j = 0; j <= o; j++)
            for (int k = 0; k <= o; k++)
                for (int u1 = 0; u1 < 3; u1++)
                    for (int u2 = 0; u2 < 3; u2++) dp[1][j][k][u1][u2]=0;
        for (int j = 0; j <= o; j++)
            for (int k = 0; k <= o; k++)
                for (int u1 = 0; u1 < 3; u1++)
                    for (int u2 = 0; u2 < 3; u2++)

        {
            if (u1==1)
            {
                dp[1][j][k+1][u2][2]=(dp[1][j][k+1][u2][2]+dp[0][j][k][u1][u2])%MOD;
                dp[1][j][k][u2][0]=(dp[1][j][k][u2][0]+dp[0][j][k][u1][u2]*24)%MOD;
            }else
            if (u1==2)
            {
                dp[1][j+1][k][u2][1]=(dp[1][j+1][k][u2][1]+dp[0][j][k][u1][u2])%MOD;
                dp[1][j][k][u2][0]=(dp[1][j][k][u2][0]+dp[0][j][k][u1][u2]*24)%MOD;
            }else
            {
                dp[1][j][k+1][u2][2]=(dp[1][j][k+1][u2][2]+dp[0][j][k][u1][u2])%MOD;
                dp[1][j+1][k][u2][1]=(dp[1][j+1][k][u2][1]+dp[0][j][k][u1][u2])%MOD;
                dp[1][j][k][u2][0]=(dp[1][j][k][u2][0]+dp[0][j][k][u1][u2]*23)%MOD;
            }
        }
        swap(dp[0],dp[1]);
    }
    for (int i = n; i > -1; i--)
    {
        pr1[i]=pr1[i+1];
        for (int u1 = 0; u1 < 2; u1++)
            for (int u2 = 0; u2 < 2; u2++) pr1[i]=(pr1[i]+dd[n][i][u1][u2])%MOD;
    }

    for (int i = n; i > -1; i--)
        for (int j = n; j > -1; j--)
        {
            pr2[i][j]=pr2[i+1][j]+pr2[i][j+1]-pr2[i+1][j+1];
            while (pr2[i][j]<0) pr2[i][j]+=MOD;
            pr2[i][j]%=MOD;
            for (int u1 = 0; u1 < 3; u1++)
                for (int u2 = 0; u2 < 3; u2++) pr2[i][j]=(pr2[i][j]+dp[0][i][j][u1][u2])%MOD;
        }
    //cout << ans << "\n";
    for (int i = 0; i < 26; i++)
    {
        ans-=pr1[c[i]+1];
        if (ans<0) ans+=MOD;
    }
    for (int i = 0; i < 26; i++)
        for (int j = i+1; j < 26; j++)
        {
            while (ans<0) ans+=MOD;
            ans=(ans+pr2[c[i]+1][c[j]+1])%MOD;
        }
    cout << ans << "\n";
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
......
MMMC
......
CCCM
.X..X.
MMM
XXXXXX
CMMCM
......
MM

*/