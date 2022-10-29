#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm, lst[500005], pr[500005];
string s, d;

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

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

struct segment_tree
{
    ll d[2000001];
    bool tt[2000001];

    void push(int h)
    {
        if (tt[h])
        {
            tt[h*2]=1;
            tt[h*2+1]=1;
            d[h*2]=0;
            d[h*2+1]=0;
            tt[h]=0;
        }
    }

    void update(int h,int l,int r,int x,int y)
    {
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]=0;
            tt[h]=1;
            return;
        }
        push(h);
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w));
        update(h*2+1,w+1,r,max(x,w+1),y);
        d[h]=(d[h*2]+d[h*2+1])%MOD;
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        push(h);
        int w=(l+r)/2;
        return (get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y))%MOD;
    }

    void upd(int h,int l,int r,int x,ll k)
    {
        if (l==r)
        {
            d[h]=(d[h]+k)%MOD;
            return;
        }
        push(h);
        int w=(l+r)/2;
        if (x<=w) upd(h*2,l,w,x,k); else upd(h*2+1,w+1,r,x,k);
        d[h]=(d[h*2]+d[h*2+1])%MOD;
    }
};

segment_tree dp0, dp1;

void solve()
{
    cin >> k >> n >> m;
    vector<pll> v;
    v.pb(mp(1, 0));
    v.pb(mp(0, 0));
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, 0));
        v.pb(mp(y+1, x));
    }

    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, 0));
        v.pb(mp(y+1, -x));
    }

    v.pb(mp(k+1, 0));

    sort(all(v));

    dp0.upd(1,0,v.size()-1,0,1);
    //dp1.upd(1,0,v.size()-1,0,1);

    /*
    cout << "  0 ::";
        for (int j = 0; j < v.size(); j++)
            cout << " " << dp0.get(1,0,v.size()-1,j,j);
        cout << "\n";

        cout << "  1 ::";
        for (int j = 0; j < v.size(); j++)
            cout << " " << dp1.get(1,0,v.size()-1,j,j);
        cout << "\n";
    */
    for (int i = 1; i < v.size(); i++)
        if (v[i].fi==v[i-1].fi)
        {
            lst[i]=lst[i-1];
        }else
        {
            lst[i]=i;
        }

    for (int i = 1; i < v.size()-1; i++)
    {
        //cout << i << " : " << v[i].fi << " " << v[i].se << " " << lst[i] << "\n";
        if (v[i].fi<v[i+1].fi)
        {
            ll p0=dp0.d[1], p1=dp1.d[1];
            //cout << "  " << p0 << " " << p1 << " " << (binpow(2, v[i+1].fi-v[i].fi-1, MOD)-1) << "\n";
            if (v[i].fi+1<v[i+1].fi)
            {
                dp0.upd(1,0,v.size()-1,lst[i],p0*(binpow(2, v[i+1].fi-v[i].fi-1, MOD)-1)%MOD);
                dp1.upd(1,0,v.size()-1,lst[i],p1*(binpow(2, v[i+1].fi-v[i].fi-1, MOD)-1)%MOD);
                dp0.upd(1,0,v.size()-1,lst[i],p1*(binpow(2, v[i+1].fi-v[i].fi-1, MOD)-1)%MOD);
                dp1.upd(1,0,v.size()-1,lst[i],p0*(binpow(2, v[i+1].fi-v[i].fi-1, MOD)-1)%MOD);
            }
            dp1.upd(1,0,v.size()-1,lst[lst[i]-1],p0);
            dp0.upd(1,0,v.size()-1,lst[lst[i]-1],p1);
        }

        if (v[i+1].se>0)
        {
            ll x=v[i+1].se;
            ll l=0, r=i;
            while (l<r)
            {
                int w=(l+r)/2;
                if (v[w].fi>=x) r=w; else l=w+1;
            }
            //cout << "   ! " << l << "\n";
            if (l) dp1.update(1,0,v.size()-1,0,l-1);
        }else
        if (v[i+1].se<0)
        {
            ll x=-v[i+1].se;
            ll l=0, r=i;
            while (l<r)
            {
                int w=(l+r)/2;
                if (v[w].fi>=x) r=w; else l=w+1;
            }
            //cout << "   ! " << l << "\n";
            if (l) dp0.update(1,0,v.size()-1,0,l-1);
        }

    }
    cout << (dp0.d[1]+dp1.d[1])%MOD << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}