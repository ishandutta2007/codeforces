#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = 1, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, k1, k2, T, K;
bool tt[500005];
vector<ll> ans;

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

pll d[500005];

void make_set(int h){
    d[h]=mp(h, 0);
}

vector<pll> qq;

ll find_set(int h)
{
    if (h==d[h].fi) return h; else return d[h].fi=find_set(d[h].fi);
}

void unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x!=y)
    {
        if (d[x].se && d[y].se)
        {
            return;
        }
        d[x].fi=y;
        d[y].se=max(d[x].se, d[y].se);
        ans.pb(T);
    }
}

bool cmp(int x,int y)
{
    return qq[x].fi<qq[y].fi || qq[x].fi==qq[y].fi && qq[x].se<qq[y].se;
}

void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) make_set(i);
    vector<pll> vv;
    vector<pair<pll, ll> > v1;
    qq.pb(mp(0, 0));
    for (int i = 1; i <= m; i++)
    {
        ll k;
        cin >> k;
        if (k==2)
        {
            ll x, y;
            cin >> x >> y;
            //qq.pb(mp(x, y));
            v1.pb(mp(mp(x, y), i));
        }else
        {
            ll x;
            cin >> x;
            //ps[x]=i;
            v1.pb(mp(mp(x, 0), i));
            //qq.pb(mp(x, 0));
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        ll x=v1[i].fi.fi, y=v1[i].fi.se;
        if (y==0)
        {
            if (d[find_set(x)].se==0)
            {
                d[find_set(x)].se=x;
                ans.pb(v1[i].se);
            }
            continue;
        }
        T=v1[i].se;
        unite_sets(x, y);
    }
    sort(all(ans));
    cout << binpow(2, ans.size(), MOD) << " " << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
MON
AMONGUS
3
*/