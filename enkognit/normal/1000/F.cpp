#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

int n, m, T, k, l, r, i, j, sum, kol=0, a[1000001], p[1000001];
map<int,vector <int> > w;
bool tt[1000001];
vector <pair<pii,int> > d[2000001];
string s, f;

void update(int h,int l,int r,int x,int y,pair<pii,int> o)
{
    //if (h==1) {cout << x << " " << y << " " << o.fi.fi << " " << o.fi.se << "\n";}
    if (x>y) return;
    if (l==x && y==r)
    {
        d[h].pb(o);
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),o);
    update(h*2+1,w+1,r,max(x,w+1),y,o);
}

int get(int h,int l,int r,int x,int y)
{
    if (d[h].size()>0)
    {
        int l1=0, r1=d[h].size()-1;
        while (l1<r1)
        {
            int w=(l1+r1+1)/2;
            if (d[h][w].fi.fi<=y) l1=w; else r1=w-1;
        }
        if (d[h][l1].fi.fi<=y && d[h][l1].fi.se>=y) return d[h][l1].se;
    }
    if (l==r)
    {
        return 0;
    }
    int w=(l+r)/2;
    if (x<=w) return get(h*2,l,w,x,y); else  return get(h*2+1,w+1,r,x,y);
}

void build(int h,int l,int r)
{
    vector <pair<pii,int> > v=d[h];
    //cout << h << " " << l << " " << r << "\n";
    d[h].clear();
    if (v.size())d[h].pb(v[0]);
    for (int i = 1; i < v.size(); i++)
        if (d[h].back().fi.se<v[i].fi.se) d[h].pb(v[i]);
    if (l==r) return;
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (w[a[i]].size()==0) w[a[i]].pb(0);
        w[a[i]].pb(i);
    }
    for (int i = 1; i <= n; i++) {if (!tt[a[i]])w[a[i]].pb(n+1), tt[a[i]]=1;}
    for (int i = 1; i <= n; i++)
    {
        p[a[i]]++;
        update(1,1,n,w[a[i]][p[a[i]]-1]+1,i,mp(mp(i,w[a[i]][p[a[i]]+1]-1), a[i]));
    }
    //cout << 1;
    build(1,1,n);
    cin >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        cout << get(1,1,n,x,y) << "\n";
    }
    return 0;
}