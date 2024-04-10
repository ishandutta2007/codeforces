#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, kol=0, q, sz=0, dp[2002][2002], mx[2002];
vector<pll> c[2001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ld get(pld x,pld y)
{
    return (x.se-y.se)/(y.fi-x.fi);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << (ll)2000*(ll)500000000%MOD*(1000000001)%MOD*999999%MOD << "\n";
    vector<pair<ll,pll> > v;
    cin >> n >> m >> q;
    vector<ll> ww;
    for (int i = 1; i <= m; i++)
    {
        ll x=i, y=i+1, h;
        //x=i;y=i+1;h=999999;
        cin >> x >> y >> h;
        c[x].pb(mp(y,h));
        c[y].pb(mp(x,h));
        v.pb(mp(h,mp(x,y)));
        ww.pb(h);
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j]=-1e18;
    dp[1][0]=0;
    for (int j = 0; j <= m; j++)
        for (int i = 1; i <= n; i++)
        {
            mx[j]=max(mx[j], dp[i][j]);
            if (dp[i][j]!=-1e18 && j<m)
            for (int u = 0; u < c[i].size(); u++)
            {
                dp[c[i][u].fi][j+1]=max(dp[c[i][u].fi][j+1], dp[i][j] + c[i][u].se);
            }
        }
    for (int i = 1; i <= m; i++) {ans+=mx[i];ans%=MOD;}

    vector<pld > fnc;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int u = 0; u < c[i].size(); u++)
            {
                fnc.pb(mp(c[i][u].se, dp[i][j]-j*c[i][u].se));
            }
    sort(all(fnc));
    vector<pair<ld,pld> > cht;
    for (int i = 0; i < fnc.size(); i++)
    {
        if (cht.size()==0) {cht.pb(mp(-1e9,fnc[i]));continue;}
        while (cht.size() && (fnc[i].fi==cht.back().se.fi && fnc[i].se>=cht.back().se.se || get(cht.back().se,fnc[i])<cht.back().fi))
            cht.pop_back();
        ld q=-1e9;
        if (cht.size()) q=get(cht.back().se,fnc[i]);
        cht.pb(mp(q,fnc[i]));
    }
    //for (int i = 0; i < cht.size(); i++) cout << cht[i].fi << " " << cht[i].se.fi << " " << cht[i].se.se << "\n";
    ll lst=m;
    for (int i = 0; i < cht.size(); i++)
    {
        ll l=ceil(cht[i].fi);
        ll r=(i+1==cht.size()?(ll)1e9:(ll)floor(cht[i+1].fi-E));
        l=max(l,lst+1);
        r=min(r,q);
        if (l>r) continue;
        lst=r;
        ll p=(r*(r+1)/2%MOD - l*(l-1)/2%MOD);
        if (p<0) p+=MOD;
        //cout << r*(r+1)/2 << " " << l*(l-1)/2 << " " << (r-l+1) << "\n";
        //cout << l << " " << r << " " << cht[i].fi << " " << cht[i].se.fi << " " << cht[i].se.se << "\n";
        p%=MOD;
        ans=((ans+(r-l+1)*(ll)cht[i].se.se%MOD)%MOD + p*(ll)cht[i].se.fi%MOD)%MOD;
        while(ans<0) ans+=MOD;
    }
    cout << ans << "\n";
    return 0;
}

/*
8 2
2 2 2 2 2 2 2 2
1 2

*/