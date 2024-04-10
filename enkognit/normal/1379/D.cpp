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

ll n, m, k, pr[200001];
pll a[200001];

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

#define dies_from_cringe exit(0)

void solve()
{
    ll h;
    cin >> n >> h >> m >> k;
    vector<pll> v;
    vector<ll> vv;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        y+=x*m;
        ll o1=y%(m/2), o2=(o1+k)%(m/2);
        //cout << o1 << " " << o2 << "\n";
        if (o1<o2)
        {
            v.pb(mp(o1+1,-1));
            v.pb(mp(o2, 1));
        }else
        {
            v.pb(mp(0, -1));
            v.pb(mp(o2,1));
            v.pb(mp(o1+1,-1));
        }
        //cout << y << " " << x*m << "\n";
        vv.pb(y);
    }
    sort(all(v));
    ll ans=0, mx=0, nw=n;
    if (v.size()==0 || v[0].fi>0) mx=n, ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        nw+=v[i].se;
        if (i+1<v.size() && v[i+1].fi==v[i].fi) continue;
        if (mx<nw) mx=nw, ans=v[i].fi;
    }
    cout << n-mx << " " << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        ll y=vv[i];
        ll o=y%(m/2);
        ll o1=ans-k, o2=ans;
        if (o1<0) o1+=m/2;
        o1%=(m/2);
        //cout << vv[i] << " " << o << " " << o1 << " " << o2 << "\n";
        if (o1<o2)
        {
            if (o1<o && o<o2) cout << i+1 << " ";
        }else
        {
            if (o<o2 || o>o1) cout << i+1 << " ";
        }
    }
    cout << "\n";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
15
asdf???c???qwer

11
abac???caba
*/