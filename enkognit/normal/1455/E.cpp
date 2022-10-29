#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ii, jj, a[100001], b[100001];
vector<pll> v;

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
    vector<pll> v;
    vector<ll> z;
    for (int i = 0; i < 4; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
        z.pb(i);
    }
    ll ans=1e18;
    do{
        vector<pll> w=v;
        for (int i = 0; i < z.size(); i++) w[i]=v[z[i]];
        ll x1=w[0].fi, x2=w[2].fi, x3=w[1].fi, x4=w[3].fi;
        ll y1=w[0].se, y2=w[1].se, y3=w[2].se, y4=w[3].se;
        if (x1>x2) swap(x1, x2);
        if (x3>x4) swap(x3, x4);
        if (y1>y2) swap(y1, y2);
        if (y3>y4) swap(y3, y4);
        ll l1=x3-x2, r1=x4-x1, l2=y3-y2, r2=y4-y1, p=0, an=x2-x1+x4-x3+y4-y3+y2-y1;
        //cout << x1 << " " << x2 << " " << x3 << " " << x4 << "\n";
        //cout << y1 << " " << y2 << " " << y3 << " " << y4 << "\n";
        //cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        //cout << an << "\n";
        if (l1>r1) swap(l1, r1);
        if (l2>r2) swap(l2, r2);
        if (max(l1,l2)<=min(r1, r2))
        {
            ll p=max(max(l1,l2), 0ll);
            an+=max(0ll,p-r1)*2;
            an+=max(0ll,p-r2)*2;
            ans=min(ans, an);
        }else
        {
            ll p=max(min(r1, r2),0ll);
            an+=max(0ll,max(p-r1, l1-p))*2;
            an+=max(0ll,max(p-r2, l2-p))*2;
            ans=min(ans, an);
        }
        //cout << an << "\n";
        //cout << "-----\n";
    }while(next_permutation(all(z)));
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/