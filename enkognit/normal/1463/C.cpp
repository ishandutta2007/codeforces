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

const ll MOD = 999999001;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, sm[2], a[1000001];

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

void solve()
{
    cin >> n;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        ll t, x;
        cin >> t >> x;
        v.pb(mp(t, x));
    }
    ll nx=0, nw=0, ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        ll tm=0;
        if (i+1==v.size())
        {
            tm=3e9;
        }else tm=v[i+1].fi;
        ll nxt=0;
        if (nx<nw)
        {
            nxt=max(nx, nw-(tm-v[i].fi));
        }else
        {
            nxt=min(nx, nw+(tm-v[i].fi));
        }
        if (nw==nx)
        {
            nx=v[i].se;
            ll nxt=0;
            if (nx<nw)
            {
                nxt=max(nx, nw-(tm-v[i].fi));
            }else
            {
                nxt=min(nx, nw+(tm-v[i].fi));
            }
            nw=nxt;
            ans+=(nxt==nx);
        }else
        {
            if (min(nw,nxt)<=v[i].se && max(nw,nxt)>=v[i].se) ans++;
            nw=nxt;
        }
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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


/*
3 2
100 100
101 101
102 102
101 101 2
105 105 2
*/