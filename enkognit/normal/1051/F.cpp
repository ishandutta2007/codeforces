#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

ll n,m,j,l,r,k,ans,vh[200001],vi[200001],dist[200001],hh[200001],dis[101][200001];
ll d[800001];
vector<pll> c[200001];
vector <ll> v;
set<pll> badedj;
map<ll,ll> t;

void dfs(ll h,ll k,ll o)
{
    t[h]=1;
    hh[h]=o;
    vh[h]=v.size();
    vi[h]=v.size();
    v.pb(h);
    dist[h]=k;
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i].fi])
    {
        t[c[h][i].fi]=1;
        dfs(c[h][i].fi,k+c[h][i].se,o+1);
        badedj.erase(mp(min(h,c[h][i].fi),max(h,c[h][i].fi)));
        vi[h]=v.size();
        v.pb(h);
    }
}

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=v[l];return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    if (hh[d[h*2]]>hh[d[h*2+1]]) d[h]=d[h*2+1]; else d[h]=d[h*2];
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;
    ll o1=get(h*2,l,w,x,min(y,w)),o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (hh[o1]>hh[o2]) return o2; else return o1;
}

void dij(ll h,ll o)
{
     set<pll> q;
     dis[o][h]=0;
     q.insert(mp(dis[o][h],h));
     while (!q.empty())
     {
         ll x=(*q.begin()).se, z=(*q.begin()).fi;
         q.erase(q.begin());
         for (int i = 0; i < c[x].size(); i++)
         {
             if (dis[o][c[x][i].fi]>dis[o][x]+c[x][i].se)
             {
                 q.erase(mp(dis[o][c[x][i].fi],c[x][i].fi));
                 dis[o][c[x][i].fi]=dis[o][x]+c[x][i].se;
                 q.insert(mp(dis[o][c[x][i].fi],c[x][i].fi));
             }
         }
     }
}

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
      ll x, y, h;
      cin >> x >> y >> h;
      c[x].pb(mp(y,h));
      c[y].pb(mp(x,h));
      if (x>y) swap(x,y);
      badedj.insert(mp(x,y));
  }
  hh[0]=1e18;
  dfs(1,0,0);
  build(1,0,v.size()-1);
  //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  //cout << "\n";
  ll i=0,k=badedj.size();
  while (badedj.size())
  {
      i++;
      for (int j = 0; j <= 100001; j++) dis[i][j]=1e18;
      dij((*badedj.begin()).fi,i);
      badedj.erase(badedj.begin());
  }
  ll z;
  cin >> z;
  for (int i = 0; i < z; i++)
{
      ll x, y;
      cin >> x >> y;
      if (x==y) {cout << 0 << "\n";continue;}
      //cout << x << " " << y << "\n";
      if (vh[x]>vh[y]) swap(x,y);
      ll p,u=get(1,0,v.size(),vh[x],vi[y]);
      if (vi[x]>vi[y]) p=dist[y]-dist[x]; else
      p=dist[x]+dist[y]-dist[u]*2;
      //cout << dist[u] << " " << dist[x] << " " << y << "-";
      for (int j = 1; j <= k; j++)
        if (dis[j][x]+dis[j][y]>0)p=min(p,dis[j][x]+dis[j][y]);
      cout << p << "\n";
  }
}