#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n,m,k,l,r=0,i,j,w,x,y,b[200001],ka[200001];pll a[200001];
map<ll,ll> c[200001];

pll d[200001];

ll dfs(ll x)
{
 ll l=1;
 for (int i=1;i<=ka[x];i++){l+=dfs(c[x][i]);}
 b[x]=l;
 return l;
}

void rec(ll x)
{
 d[x].fi=y;d[y].se=x;
 for (int i=1;i<=ka[x];i++)
 {
  y++;
  rec(c[x][i]);
 }
}

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=2;i<=n;i++)
  {
   cin >> x;
   ka[x]++;
   c[x][ka[x]]=i;
  }
  b[1]=dfs(1);
  y=1;
  rec(1);
  //for (i=1;i<=n;i++) cout << d[i].fi << " ";
  for (i=1;i<=m;i++)
  {
   cin >> a[i].fi >> a[i].se;
   if (b[a[i].fi]<a[i].se) cout << -1 << "\n"; else
   cout << d[d[a[i].fi].fi+a[i].se-1].se << "\n";
  }
  return 0;
}