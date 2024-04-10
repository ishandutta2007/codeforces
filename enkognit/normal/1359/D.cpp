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
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, md1 = MOD, md2 = 998244353;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, a[1000001];
ll t;
vector<ll> v;

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

ld func(ld h)
{
    return abs(h-t);
}

/*void rec(int l,int r)
{
    if (l>r) return;
    int w=(l+r)/2;
    vector<ll> prl, prr;
    vector<ll> vl, vr;
    prl.pb(0);
    prr.pb(0);
    vl.pb(mp(w,0));
    vr.pb(mp(w,0));
    for (int i = w-1; i >= l; i--)
    {
        prl.pb(prl.back()+a[i]);
        if (a[i]<=vl.back().fi) vl.back().se=i; else vl.pb(mp(a[i],i));
    }
    for (int i = w+1; i <= r; i++)
    {
        prr.pb(prr.back()+a[i]);
        if (a[i]<=vr.back().fi) vr.back().se=i; else vr.pb(mp(a[i],i));
    }

}*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans=0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int it = 30; it > -31; it--)
    {
        ll sum=0, mn=0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i]<=it)
            {
                sum+=a[i];
                mn=min(mn,sum);
                if (sum!=mn)ans=max(ans, sum-mn-it);
            }else
            {
                mn=0, sum=0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
7 6
2 1 1
3 1 2
1 4 0
4 5 1
5 6 3
5 7 4
1 3
4 1
2 4
2 5
3 5
3 7
*/