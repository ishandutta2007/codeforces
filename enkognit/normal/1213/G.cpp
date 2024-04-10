#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, l, r, i, j, x, y, ans, a[200001];
ll tt[200001];


struct dsu
{
    ll d[200001];

    void make_set(ll h)
    {
        d[h]=h;
    }

    ll get(ll h)
    {
        if (h==d[h]) return h; else return d[h]=get(d[h]);
    }

    void unite_sets(ll a,ll b)
    {
        a=get(a);
        b=get(b);
        if (a!=b)
        {
            d[b]=a;
            ans-=tt[a]*(tt[a]-1)/2;
            ans-=tt[b]*(tt[b]-1)/2;
            tt[a]+=tt[b];
            ans+=(tt[a]*(tt[a]-1))/2;
        }
    }
};

dsu p;
vector <pair<ll,pll> > v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        v.pb(mp(z,mp(x,y)));
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        v.pb(mp(x,mp(1e18,i)));
    }
    sort(v.begin(),v.end());
    for (int i = 1; i <= n; i++) p.make_set(i),tt[i]=1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].se.fi==1e18)
        {
            a[v[i].se.se]=ans;
        }else
        {
            p.unite_sets(v[i].se.fi, v[i].se.se);
        }
    }
    for (int i = 0; i < m; i++) cout << a[i] << " ";
    return 0;
}
/*
10 3
9 30 45 2 5 7 10 3 16 22
*/