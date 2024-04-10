#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define y1 Enkognit
#define ld long double
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll INF=1e18;
const ll MOD=1e9+7;

template<typename T>
using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll p1=137, p2=91;

ll n, m, k, l, r;
string s;

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

struct segment_tree
{
    ll d[1000001];
    pair<pll,pll> hs[1000001];

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            if (s[l]=='0')
            {
                d[h]=1;
                hs[h].fi.fi=29+(l%2)*2;
                hs[h].fi.se=29+(l%2)*2;
                hs[h].se.fi=31-(l%2)*2;
                hs[h].se.se=31-(l%2)*2;
            }
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=d[h*2]+d[h*2+1];
        hs[h].fi.fi=(hs[h*2].fi.fi+(hs[h*2+1].fi.fi*binpow(p1,d[h*2]))%MOD)%MOD;
        hs[h].fi.se=(hs[h*2].fi.se+(hs[h*2+1].fi.se*binpow(p2,d[h*2]))%MOD)%MOD;
        hs[h].se.fi=(hs[h*2].se.fi+(hs[h*2+1].se.fi*binpow(p1,d[h*2]))%MOD)%MOD;
        hs[h].se.se=(hs[h*2].se.se+(hs[h*2+1].se.se*binpow(p2,d[h*2]))%MOD)%MOD;
    }

    pair<ll,pll> get(int h,int l,int r,int x,int y,bool t)
    {
        //cout << l << " " << r << " " << x << " " << y << "\n";
        if (x>y) return mp(0,mp(0,0));
        if (l==x && y==r)
        {
            if (!t)
            return mp(d[h],hs[h].se); else return mp(d[h],hs[h].fi);
        }
        int w=(l+r)/2;
        pair<ll,pll> o1=get(h*2,l,w,x,min(y,w),t), o2=get(h*2+1,w+1,r,max(x,w+1),y,t);
        pair<ll,pll> o3;
        o3.fi=o1.fi+o2.fi;
        o3.se.fi=(o1.se.fi+(o2.se.fi*binpow(p1,o1.fi))%MOD)%MOD;
        o3.se.se=(o1.se.se+(o2.se.se*binpow(p2,o1.fi))%MOD)%MOD;
        return o3;
    }
};

segment_tree g;

void solve()
{
    cin >> n;
    cin >> s;
    s=' '+s;
    g.build(1,1,n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        pair<ll,pll> o1=g.get(1,1,n,x,x+z-1,x%2), o2=g.get(1,1,n,y,y+z-1,y%2);
        if (o1.fi!=o2.fi || o1.se.fi!=o2.se.fi || o1.se.se!=o2.se.se) cout << "No\n"; else cout << "Yes\n";
    }
}

int main()
{
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