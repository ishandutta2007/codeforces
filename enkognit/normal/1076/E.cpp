#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>

using namespace std;

ll n,m,i,j,k,l=0,x,y,h,r,o,p=0,d[500001],f[500001];vector <pll> a[300001];

string s;
map <ll,ll> t;
vector <ll> c[300001];

void dfs(ll x,ll h,ll u,ll* z)
{
 t[x]=1;
 ll o=u;
 for (int i=0;i<a[x].size();i++)
 {
  z[h+min(a[x][i].fi,n+2-h)]+=a[x][i].se;
  u+=a[x][i].se;
 }
 d[x]+=u;
 u-=z[h];
 for (int i=0;i<c[x].size();i++) if (!t[c[x][i]])dfs(c[x][i],h+1,u,z);
 for (int i=0;i<a[x].size();i++)
 {
  z[h+min(a[x][i].fi,n+2-h)]-=a[x][i].se;
 }
 u=o;
}

int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n-1;i++)
  {
   ll x,y;
   cin >> x >> y;
   c[x].pb(y);
   c[y].pb(x);
  }
  cin >> m;
  for (i=0;i<m;i++)
  {
   ll x,y,h;
   cin >> x >> y >> h;
   a[x].pb(mp(y,h));
  }
  dfs(1,0,0,f);
  for (i=1;i<=n;i++) cout << d[i] << " ";
  return 0;
}