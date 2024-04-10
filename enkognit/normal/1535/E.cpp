#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, q, a[300001], c[300001], pp[300001], bn[300001][20];
string s;

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

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void upd(int h)
{
    bn[h][0]=pp[h];
    for (int i = 1; i < 20; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];
}

ll gt(int h)
{
    for (int i = 19; i > -1; i--)
        if (a[bn[h][i]]>0) h=bn[h][i];
    return h;
}

void solve()
{
    cin >> q >> a[0] >> c[0];
    ll kl=0;
    //fflush(stdout);
    while (q--)
    {
        kl++;
        ll t;
        cin >> t;
        if (t==1)
        {
            ll p, x, y;
            cin >> p >> x >> y;
            a[kl]=x;
            c[kl]=y;
            pp[kl]=p;
            upd(kl);
        }else
        {
            ll x, y, ans=0, e=0;
            cin >> x >> y;
            //-cout << a[x] << "\n";
            while (a[x]>0 && y>0)
            {
                ll u=gt(x);
                ll p=min(a[u], y);
                y-=p;
                a[u]-=p;
                e+=p;
                ans+=p*c[u];
            }
            cout << e << " " << ans << endl;
        }
        //fflush(stdout);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}
*/