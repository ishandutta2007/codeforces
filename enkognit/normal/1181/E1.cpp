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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T;
pll a[300001], b[300001];
ll tt[300001];

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

struct dsu
{
    ll d[200001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x<y) swap(x,y);
        d[x]=y;
    }
};

bool rec(vector<ll> &v)
{
    if (v.size()==1) return 1;
    vector<pair<pll, ll> > vx, vy;
    for (int i = 0; i < v.size(); i++)
    {
        vx.pb(mp(mp(a[v[i]].fi,1),v[i]));
        vx.pb(mp(mp(a[v[i]].se,0),v[i]));
        vy.pb(mp(mp(b[v[i]].fi,1),v[i]));
        vy.pb(mp(mp(b[v[i]].se,0),v[i]));
        tt[v[i]]=0;
    }
    sort(all(vx));
    sort(all(vy));

    ll kl=0, u=-1;
    for (int i = 0; i < vx.size(); i++)
    {
        if (i>0)
        {
            if (kl==0)
            {
                u=i;
                break;
            }
        }
        kl+=(tt[vx[i].se]==0?1:-1);
        tt[vx[i].se]++;
    }
    if (u!=-1)
    {
        vector<ll> v1, v2;
        for (int i = 0; i < v.size(); i++) if (tt[v[i]]==2) v1.pb(v[i]); else v2.pb(v[i]);
        return (rec(v1)&rec(v2));
    }

    for (int i = 0; i < v.size(); i++) tt[v[i]]=0;

    kl=0, u=-1;
    for (int i = 0; i < vy.size(); i++)
    {
        if (i>0)
        {
            if (kl==0)
            {
                u=i;
                break;
            }
        }
        kl+=(tt[vy[i].se]==0?1:-1);
        tt[vy[i].se]++;
    }
    if (u!=-1)
    {
        vector<ll> v1, v2;
        for (int i = 0; i < v.size(); i++) if (tt[v[i]]==2) v1.pb(v[i]); else v2.pb(v[i]);
        return (rec(v1)&rec(v2));
    }
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> b[i].fi >> a[i].se >> b[i].se;
        v.pb(i);
    }
    cout << (rec(v)?"YES\n":"NO\n");
    return 0;
}

/*

*/