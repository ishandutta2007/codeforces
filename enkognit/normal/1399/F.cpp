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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, P, dp[10001], a[200001], dpp[10001];
vector<pll> pp[10001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
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

void solve()
{
    cin >> n;
    vector<pair<int,pii> > v;
    vector<pii> vv;
    vector<int> uu;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vv.pb(mp(x, y));
        uu.pb(x);
        uu.pb(y);
    }
    sort(all(uu));
    ll k=0;
    for (int i = 0; i < uu.size(); i++)
    {
        if (i==0 || uu[i]!=uu[i-1]) k++;
        a[uu[i]]=k;
    }
    for (int i = 0; i < n; i++)
    {
        ll x=a[vv[i].fi], y=a[vv[i].se];
        v.pb(mp(y-x,mp(x,y)));
    }
    v.pb(mp(2*n+1,mp(0, 2*n+1)));
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
            if (v[i].se.fi<=v[j].se.fi && v[i].se.se>=v[j].se.se)
            {
                pp[v[j].se.fi].pb(mp(v[j].se.se, dp[j]));
            }
        ll ans=0;
        for (int u = v[i].se.fi; u <= v[i].se.se; u++)
        {
            ans=max(ans, dpp[u]);
            dpp[u+1]=max(dpp[u+1], dpp[u]);
            for (int j = 0; j < pp[u].size(); j++)
                dpp[pp[u][j].fi+1]=max(dpp[u]+pp[u][j].se, dpp[pp[u][j].fi+1]);
            dpp[u]=0;
            pp[u].clear();
        }
        dp[i]=max(ans,dpp[v[i].se.se+1])+(i+1!=v.size());
        //cout << v[i].se.fi << " " << v[i].se.se << " " << dp[i] << "\n";
        dpp[v[i].se.se+1]=0;
    }
    cout << dp[v.size()-1] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}