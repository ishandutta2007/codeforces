#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=998244353;

ll n, m, k, T, sm, dp[1005][1005][2], kl1[1005], kl2[1005];
int tt[20000001];
string s, d;

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{


    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

//vector<ll> z;

void solve()
{
    cin >> s;
    cin >> d;
    s=' '+s;
    d=' '+d;
    for (int i = 1; i < s.size(); i++)
        if (s[i]!=s[i-1]) kl1[i]=kl1[i-1]+1; else kl1[i]=1;

    for (int i = 1; i < d.size(); i++)
        if (d[i]!=d[i-1]) kl2[i]=kl2[i-1]+1; else kl2[i]=1;

    for (int i = 1; i < s.size(); i++)
        for (int j = 1; j < d.size(); j++)
            if (s[i]!=d[j])
            {
                //cout << kl1[i] << " " << kl2[j] << "\n";
                dp[i][j][0]=kl2[j], dp[i][j][1]=kl1[i];
            }
    ll ans=0;
    for (int i = 1; i < s.size(); i++)
        for (int j = 1; j < d.size(); j++)
            for (int u = 0; u < 2; u++)
                if (dp[i][j][u])
                {
                    if (i+1<s.size() && (u==0 && s[i+1]!=s[i] || u==1 && s[i+1]!=d[j]))
                    {
                        dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][u])%MOD;
                    }

                    if (j+1<d.size() && (u==0 && d[j+1]!=s[i] || u==1 && d[j+1]!=d[j]))
                    {
                        dp[i][j+1][1]=(dp[i][j+1][1]+dp[i][j][u])%MOD;
                    }
                    ans=(ans+dp[i][j][u])%MOD;
                }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}