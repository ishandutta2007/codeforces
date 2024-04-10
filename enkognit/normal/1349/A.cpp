#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, m, k, h, T, a[200001], kl[200001];
pll b[200001];

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;// l %= md;
        h *= h;
        //h %= md;
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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 200000; i++) b[i]=mp(1e18,1e18);
    vector<ll> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll x=a[i], p=sqrt(x);
        vector<pll> v;
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                v.pb(mp(j,0));
                while (x%j==0) v.back().se++, x/=j;
            }
        if (x>1) v.pb(mp(x,1));
        for (int i = 0; i < v.size(); i++)
        {
            kl[v[i].fi]++;
            if (kl[v[i].fi]==n-1) w.pb(v[i].fi);
            if (b[v[i].fi].fi>v[i].se) swap(b[v[i].fi].fi,b[v[i].fi].se), b[v[i].fi].fi=v[i].se;else
            if (b[v[i].fi].se>v[i].se) b[v[i].fi].se=v[i].se;
        }
    }
    ll ans=1;
    for (int i = 0; i < w.size(); i++)
    {
        if (kl[w[i]]==n) ans*=binpow(w[i],b[w[i]].se); else
            ans*=binpow(w[i],b[w[i]].fi);
    }
    cout << ans << "\n";
    return 0;
}