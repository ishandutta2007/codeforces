#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, l, r, dp[41][2][2][2][2];
string s, d;
vector <pll> v, an;
set <pair<ll, pll> > z;
bool tt[1000001];

void solve()
{
    cin >> n >> m;
    string l, r;
    ll j=39;
    while (j--)
    {
        l+=n%2+48;
        n/=2;
    }
    j=39;
    while (j--)
    {
        r+=m%2+48;
        m/=2;
    }
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    //cout << l << " " << r << "\n";
    for (int i = 0; i < 41; i++)
        for (int i1 = 0; i1 < 2; i1++)
        for (int i2 = 0; i2 < 2; i2++)
        for (int i3 = 0; i3 < 2; i3++)
        for (int i4 = 0; i4 < 2; i4++) dp[i][i1][i2][i3][i4]=0;
    dp[0][1][1][1][1]=1;
    for (int i = 0; i < 39; i++)
        for (int i1 = 0; i1 < 2; i1++)
        for (int i2 = 0; i2 < 2; i2++)
        for (int i3 = 0; i3 < 2; i3++)
        for (int i4 = 0; i4 < 2; i4++)
            if (dp[i][i1][i2][i3][i4])
        {
            pll st1=mp(0,1), st2=mp(0,1);
            if (i1==1) st1.fi=max(st1.fi,l[i]-48ll);
            if (i2==1) st1.se=min(st1.se,r[i]-48ll);
            if (i3==1) st2.fi=max(st2.fi,l[i]-48ll);
            if (i4==1) st2.se=min(st2.se,r[i]-48ll);
            for (int j = st1.fi; j <= st1.se; j++)
                for (int u = st2.fi; u <= st2.se; u++)
                    if (!(j==1 && u==1))
                {
                    int j1, j2, j3, j4;
                    if (j>l[i]-48) j1=0; else j1=i1;
                    if (j<r[i]-48) j2=0; else j2=i2;
                    if (u>l[i]-48) j3=0; else j3=i3;
                    if (u<r[i]-48) j4=0; else j4=i4;
                    dp[i+1][j1][j2][j3][j4]+=dp[i][i1][i2][i3][i4];
                }
        }
    ll ans=0;
    for (int i1 = 0; i1 < 2; i1++)
    for (int i2 = 0; i2 < 2; i2++)
    for (int i3 = 0; i3 < 2; i3++)
    for (int i4 = 0; i4 < 2; i4++) ans+=dp[39][i1][i2][i3][i4];
    //cout << "\n";
    cout << ans << "\n";
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}