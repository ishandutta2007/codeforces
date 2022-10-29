#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>

using namespace std;

ll n,i,j,p,x,y,u,m,xx,yy,l,r,k=0;
string s,d;char c;
bool t[2001][2001];pll g[2001][2001];
queue <pll> q;

void add(ll x,ll y,ll l,ll r)
{
 if (x<1 || y<1 || y>m || x>n || t[x][y] || g[x][y].fi<=l || g[x][y].se<=r) return;
 g[x][y]=mp(l,r);
 q.pu(mp(x,y));
}

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> xx >> yy;
  cin >> l >> r;
  for (i=1;i<=n;i++)
  {
   cin >> s;
   for (j=0;j<m;j++) {t[i][j+1]=(s[j]=='*');g[i][j+1]=mp(1e9,1e9);}
  }
  g[xx][yy]=mp(0,0);
  q.pu(mp(xx,yy));
  while (!q.empty())
  {
   ll x=q.fr.fi,y=q.fr.se;
   add(x,y+1,g[x][y].fi,g[x][y].se+1);
   add(x,y-1,g[x][y].fi+1,g[x][y].se);
   add(x+1,y,g[x][y].fi,g[x][y].se);
   add(x-1,y,g[x][y].fi,g[x][y].se);
   q.pop();
  }
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
  {
   if (g[i][j].fi<=l && g[i][j].se<=r && !t[i][j]) {k++;}
  }
  cout << k;
  /*for (i=1;i<=n;i++)
  {
   for (j=1;j<=m;j++)
   {
    if (t[i][j]) cout << 2 << " ";  else
    if (g[i][j]) cout << 1 << " ";  else
    cout << 0 << " ";
   }
   cout << "\n";
  }*/
  return 0;
}