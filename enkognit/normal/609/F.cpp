#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
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
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, ans[200001];pll an[200001];
pair<pll,ll> a[200001];
vector<ll> v;
string s;

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

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct segment_tree
{
    ll d[1000001];

    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=a[l].fi.fi+a[l].fi.se;return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    void update(int h,int l,int r,int x,ll k)
    {
        if (l==r) {d[h]=k;return;}
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree g;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {cin >> a[i].fi.fi >> a[i].fi.se;a[i].se=i;}
    sort(a+1,a+n+1);
    g.build(1,1,n);
    multiset<pair<int,ll> > s;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        //cout << "------\n";
        cin >> x >> y;
        //cout << x << " : " << y << "\n";
        ll l=1, r=n;
        while (l<r)
        {
            int w=(l+r)/2;
            if (g.get(1,1,n,1,w)>=x) r=w; else l=w+1;
        }
        if (a[l].fi.fi>x || g.get(1,1,n,l,l)<x)
        {
            s.insert(mp(x,y));
        }else
        {
            ll p=g.get(1,1,n,l,l);
            p+=y;
            //cout << a[l].se << " " << p << " - \n";
            ans[l]++;
            while (s.size())
            {
                auto u = s.upper_bound(mp(p,1e9));
                if (u==s.begin()) break;
                u--;
                if ((*u).fi<a[l].fi.fi) break;
                p+=(*u).se;
                ans[l]++;
                s.erase(u);
            }
            g.update(1,1,n,l,p);
            //cout << p << "\n";
        }
    }
    for (int i = 1; i <= n; i++) an[a[i].se]=mp(ans[i], g.get(1,1,n,i,i)-a[i].fi.fi);
    for (int i = 1; i <= n; i++) cout << an[i].fi << " " << an[i].se << "\n";
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/