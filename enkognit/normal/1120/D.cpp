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

const ll MOD=1e9+7;

ll n, m, k, T, sm, a[200005], dp[200005][2];
vector<ll> c[200005], v;
vector<pll> vv[200005];
int tt[200005][2];

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

void dfs(int h,int p=-1)
{
    if (h!=1 && c[h].size()==1)
    {
        dp[h][1]=0;
        dp[h][0]=a[h];
        //cout << h << " : " << dp[h][0] << " " << dp[h][1] << "\n";
        return;
    }
    ll sm=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            sm+=dp[c[h][i]][0];
        }
    dp[h][0]=sm;
    dp[h][1]=1e18;

    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            sm-=dp[c[h][i]][0];
            sm+=dp[c[h][i]][1];
            dp[h][0]=min(dp[h][0], sm+a[h]);
            dp[h][1]=min(dp[h][1], sm);
            sm+=dp[c[h][i]][0];
            sm-=dp[c[h][i]][1];
        }
    //cout << h << " : " << dp[h][0] << " " << dp[h][1] << " " << sm << "\n";
}

void dfs2(int h,int k,int p=-1)
{
    tt[h][k]=2;

    //cout << h << " " << k << " " << dp[h][k] << "\n";

    if (h!=1 && c[h].size()==1)
    {
        if (k==0)
        {
            v.pb(h);
        }
        return;
    }

    ll sm=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            sm+=dp[c[h][i]][0];
        }

    if (k==1)
    {
        ll kl=0, pp=0;
        for (int i = 0; i < c[h].size(); i++)
            if (c[h][i]!=p)
            {
                sm-=dp[c[h][i]][0];
                sm+=dp[c[h][i]][1];

                if (sm==dp[h][k])
                {
                    kl++;
                    pp=c[h][i];
                    tt[c[h][i]][1]=max(1, tt[c[h][i]][1]);
                }

                sm+=dp[c[h][i]][0];
                sm-=dp[c[h][i]][1];
            }

        for (int i = 0; i < c[h].size(); i++)
            if (c[h][i]!=p)
            {
                if (kl==1)
                {
                    if (pp!=c[h][i])
                    {
                        tt[c[h][i]][0]=max(1, tt[c[h][i]][0]);
                    }
                }else
                if (kl>1)
                {
                    tt[c[h][i]][0]=max(1, tt[c[h][i]][0]);
                }
            }
    }else
    {
        //cout << " " << sm << "\n";
        if (sm==dp[h][k])
        {
            for (int i = 0; i < c[h].size(); i++)
                if (c[h][i]!=p) tt[c[h][i]][0]=max(1, tt[c[h][i]][0]);
        }

        ll kl=0, pp=0;
        for (int i = 0; i < c[h].size(); i++)
            if (c[h][i]!=p)
            {
                sm-=dp[c[h][i]][0];
                sm+=dp[c[h][i]][1];

                if (sm+a[h]==dp[h][k])
                {
                    kl++;
                    pp=c[h][i];
                    if (kl==1) v.pb(h);
                    tt[c[h][i]][1]=max(1, tt[c[h][i]][1]);
                }

                sm+=dp[c[h][i]][0];
                sm-=dp[c[h][i]][1];
            }

        for (int i = 0; i < c[h].size(); i++)
            if (c[h][i]!=p)
            {
                if (kl==1)
                {
                    if (pp!=c[h][i])
                    {
                        tt[c[h][i]][0]=max(1, tt[c[h][i]][0]);
                    }
                }else
                if (kl>1)
                {
                    tt[c[h][i]][0]=max(1, tt[c[h][i]][0]);
                }
            }
    }

    for (int i = 0; i < c[h].size(); i++)
    {
        //cout << "  " << c[h][i] << " " << tt[c[h][i]][0] << " " << tt[c[h][i]][1] << "\n";
        if (tt[c[h][i]][0]==1) dfs2(c[h][i], 0, h);
        if (tt[c[h][i]][1]==1) dfs2(c[h][i], 1, h);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    cout << dp[1][0] << " ";
    dfs2(1, 0);
    cout << v.size() << "\n";
    sort(all(v));
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}