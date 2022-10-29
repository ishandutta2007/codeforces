#include <bits/stdc++.h>

#define len length()
#define ll long long
#define pu push
#define mp make_pair
#define fr front()
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>

using namespace std;

ll n,k,m,i,j,l,x[1001],y[1001],ka[1001],kb[1001];
ll a[1001][1001],b[1001][1001];
bool t[1001][1001];
queue <pll> q;

void add(ll x,ll y)
{
 if (t[x][y]) return;
 t[x][y]=1;
 q.pu(mp(x,y));
}

int main()
{
   //freopen("bike.in","r",stdin);
   //freopen("bike.out","w",stdout);
   cin >> n;
   for (i=1;i<=n;i++)
   {
    cin >> x[i] >> y[i];
    ka[x[i]]++;
    a[x[i]][ka[x[i]]]=y[i];
    kb[y[i]]++;
    b[y[i]][kb[y[i]]]=x[i];
   }
   for (i=1;i<=n;i++)
    if (!t[x[i]][y[i]])
   {
    add(x[i],y[i]);
    while (!q.empty())
    {
     ll x=q.fr.fi,y=q.fr.se;
     q.pop();
     for (int j=1;j<=ka[x];j++)add(x,a[x][j]);
     for (int j=1;j<=kb[y];j++)add(b[y][j],y);
    }
    l++;
   }
   cout << l-1;
   return 0;
}