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

ll n,i,j,p,x,y,u,m,xx,yy,l,r,k,a[300001];
string s,d;char c;
bool t[2001][2001],g[2001][2001];
queue <pair<pll,pll> > q;

void add(ll x,ll y,ll l,ll r)
{
 if (x<0 || y<0 || y>=m || x>=n || t[x][y] || g[x][y]) return;
 if (!g[x][y]) g[x][y]=1,k++;
 q.pu(mp(mp(x,y),mp(l,r)));
}

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> x;l=0;
   while (x) l+=x%2,x/=2;
   cout << (1<<l) << "\n";
  }
  //for (i=0;i<n;i++) {for (j=0;j<m;j++) cout << g[i][j] << " ";cout << "\n";}
  return 0;
}
/*cin >> n >> m;
  cin >> xx >> yy;
  cin >> l >> r;
  for (i=0;i<n;i++)
  {
   cin >> s;
   for (j=0;j<s.size();j++) t[i][j]=(s[j]=='*');
  }
  q.pu(mp(mp(xx-1,yy-1),mp(l,r)));
  while (!q.empty())
  {
   ll x=q.fr.fi.fi,y=q.fr.fi.se,u=q.fr.se.fi,o=q.fr.se.se;
   if (o>0) add(x,y+1,u,o-1);
   if (u>0) add(x,y-1,u-1,o);
   add(x+1,y,u,o);
   add(x-1,y,u,o);
   q.pop();
  }
  cout << k << "\n";*/