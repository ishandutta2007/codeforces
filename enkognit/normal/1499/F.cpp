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

ll n, m, k, T, sm, kl[5001];
int dp[5001][5001], an[5001][5001];
vector<ll> c[5005];
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

void dfs(int h,int p=-1)
{
    if (h!=1 && c[h].size()==1)
    {
        dp[h][0]=1;
        an[h][1]=1;
        return;
    }
    bool t=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
        }
    //cout << h << " :\n";
    for (int i = 0; i <= m; i++) kl[i]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            ll pr=0;
            for (int j = 0; j <= m; j++)
            {
                pr=(pr+dp[c[h][i]][j])%MOD;
            }
            for (ll j = 0; j <= m; j++)
            {
                if (j) pr=(pr+dp[c[h][i]][j-1])%MOD;
                if (j<=m/2)
                {
                    an[c[h][i]][m-j]=((ll)an[c[h][i]][m-j]*(ll)kl[j])%MOD;
                }
                kl[j]=(kl[j]*pr)%MOD;
            }
            t=1;
        }

    for (int i = 0; i <= m/2; i++)
    {
        dp[h][i]=(kl[i]-(i?kl[i-1]:0));
        if (dp[h][i]<0) dp[h][i]+=MOD;
    }

    for (int i = 0; i <= m; i++) kl[i]=1;

    for (int i = c[h].size()-1; i > -1; i--)
        if (c[h][i]!=p)
        {
            ll pr=0;
            for (int j = 0; j <= m; j++)
            {
                pr=(pr+dp[c[h][i]][j])%MOD;
            }
            for (ll j = 0; j <= m; j++)
            {
                if (j) pr=(pr+dp[c[h][i]][j-1])%MOD;
                if (j<=m/2)
                {
                    //cout << " " << kl[h][j] << " " << m-j << "\n";
                    an[c[h][i]][m-j]=((ll)an[c[h][i]][m-j]*(ll)kl[j])%MOD;
                }
                kl[j]=(kl[j]*pr)%MOD;
            }
            t=1;
        }

    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            for (int j = m/2+1; j <= m; j++)
                dp[h][j]=(dp[h][j]+an[c[h][i]][j])%MOD;
        }

    for (int i = 0; i < m; i++) an[h][i+1]=dp[h][i];
}

void solve()
{
    cin >> n >> m;
    if (m==0)
    {
        cout << "1\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    ll ans=0;
    for (int i = 0; i <= m; i++) ans=(ans+dp[1][i])%MOD;
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