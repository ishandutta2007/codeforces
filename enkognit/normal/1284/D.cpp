#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(time(NULL));

ll n, m, k, i, j, mx=0, kl=0, T=0, an[1000001];
pair<pll,ll> a[200001], b[200001], c[200001], dd[200001];
ll tt[1000001];
vector <pll> v;
ll d[2000001];

bool comp(pll x,pll y)
{
    return (x.fi>y.fi || (x.fi==y.fi && x.fi>y.fi));
}

void build(int h,int l,int r)
{
    if (l==r) {d[h]=b[l].se;return;}
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) tt[a[i].se]=i, a[i].se=i;
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++) b[i].se=tt[b[i].se];
    build(1,1,n);
    set<pii> s1;
    set<int> s2;
    for (int i = 1; i <= n; i++)
    {
        ll l=i, r=n;
        while (l<r)
        {
            ll w=(l+r+1)/2;
            if (b[w].fi.fi>b[i].fi.se) r=w-1; else l=w;
        }
        ll p=b[i].se;
        while (s1.size() && (*s1.begin()).fi<b[i].fi.fi) s2.erase(1e9-(*s1.begin()).se),s1.erase(s1.begin());
        if (s2.size()>0)
        {
            //cout << (ll)1e9-(*s2.begin()) << "\n";
            p=max((ll)1e9-(*s2.begin()),p);
        }
        ll o=get(1,1,n,i,l);
        //cout << b[i].se << " " << b[i].fi.fi << " " << b[i].fi.se << " " << p << " " << o << "\n";
        an[b[i].se]=max(o,p);
        s2.insert(1e9-b[i].se);
        s1.insert(mp(b[i].fi.se,b[i].se));
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << i << " " << an[i] << "\n";
        if (a[an[i]].fi.fi>a[i].fi.se) {cout << "NO\n";exit(0);}
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se >> b[i].fi.fi >> b[i].fi.se;
        a[i].se=i;
        b[i].se=i;
    }
    for (int i = 1; i <= n; i++) c[i]=a[i], dd[i]=b[i];
    solve();
    for (int i = 1; i <= n; i++) a[i]=dd[i], b[i]=c[i];
    solve();
    cout << "YES\n";
    return 0;
}
/*
4
101
10001
1
10
1101
*/