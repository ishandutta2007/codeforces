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

ll n, m, k, sz, a[200005], b[200005];
vector<pll> v1, v2;

ll binpow(ll h,ll r,ll md)
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

struct node
{
    node *l, *r;
    ll a, b, y;
    ll mn1, mn2;
    ll z1, z2;
    //node():l(nullptr),r(nullptr),a(0),b(0),y(rnd()%MOD),mn1(1e18),mn2(1e18),z1(1e18),z2(1e18){};
    node(ll a,ll b):l(nullptr),r(nullptr),a(a),b(b),y(rnd()%MOD),mn1(2*a),mn2(-(b-a)*2),z1(2*a),z2(-(b-a)*2){};
};

void upd(node *h)
{
    if (!h) return;
    h->z1=min(h->mn1, min((h->l?h->l->z1:(ll)1e18), (h->r?h->r->z1:(ll)1e18)));
    h->z2=min(h->mn2, min((h->l?h->l->z2:(ll)1e18), (h->r?h->r->z2:(ll)1e18)));
}

node* merge(node *l,node *r)
{
    if (!l) return r;
    if (!r) return l;
    if (l->y>r->y)
    {
        l->r=merge(l->r,r);
        upd(l);
        return l;
    }else
    {
        r->l=merge(l,r->l);
        upd(r);
        return r;
    }
}

pair<node*,node*> split(node *h,ll k)
{
    if (!h) return mp(nullptr,nullptr);
    //cout << k << "\n";
    if (h->b>k)
    {
        auto tt=split(h->l,k);
        h->l=tt.se;
        upd(h);
        return mp(tt.fi, h);
    }else
    {
        auto tt=split(h->r,k);
        h->r=tt.fi;
        upd(h);
        return mp(h, tt.se);
    }
}

node* root=nullptr;

void _insert(ll a,ll b)
{
    auto ww=split(root, b);
    root=merge(merge(ww.fi, new node(a, b)), ww.se);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll sm=0;
    for (int i = 1; i <= n; i++)
    {
        sm+=abs(b[i]-a[i]);
        if (a[i]<b[i])
        {
            v1.pb(mp(a[i], b[i]));
        }else
        if (b[i]<a[i])
        {
            v2.pb(mp(b[i], a[i]));
        }
    }
    sort(all(v1));
    sort(all(v2));
    ll l=v2.size(), ans=sm;
    for (int i = v1.size()-1; i > -1; i--)
    {
        while (l>0 && v2[l-1].fi>=v1[i].fi)
        {
            l--;
            _insert(v2[l].fi, v2[l].se);
        }
        //cout << i << " " << v1[i].fi << " " << v1[i].se << "\n";
        if (!root) continue;
        //cout << "--\n";
        auto ww=split(root,v1[i].se);
        //cout << "--\n";
        if (ww.fi)
        {
            //cout << "-\n";
            ans=min(ans,sm+ww.fi->z2);
        }
        if (ww.se)
        {
            //cout << "-\n";
            ans=min(ans,sm-v1[i].se*2+ww.se->z1);
        }
        root=merge(ww.fi, ww.se);
    }
    swap(v1,v2);
    l=v2.size();
    root=nullptr;
    for (int i = v1.size()-1; i > -1; i--)
    {
        while (l>0 && v2[l-1].fi>=v1[i].fi)
        {
            l--;
            _insert(v2[l].fi, v2[l].se);
        }
        //cout << i << " " << v1[i].fi << " " << v1[i].se << "\n";
        if (!root) continue;
        //cout << "--\n";
        auto ww=split(root,v1[i].se);
        //cout << "--\n";
        if (ww.fi)
        {
            //cout << "-\n";
            ans=min(ans,sm+ww.fi->z2);
        }
        if (ww.se)
        {
            //cout << "-\n";
            ans=min(ans,sm-v1[i].se*2+ww.se->z1);
        }
        root=merge(ww.fi,ww.se);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/