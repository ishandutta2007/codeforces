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

ll n,m,k,l,r,i,j,w,x,y,p,b[200001],c[200001];
bool t;
string s,d;

struct thll{ll fi,se,th;};

thll a[200001];

bool comp(thll x,thll y)
{
 if (x.fi<y.fi) return 1; else return 0;
}

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++)  cin >> a[i].fi;
  for (i=1;i<=n;i++)  {cin >> a[i].se;a[i].th=i;}
  sort(a+1,a+n+1,comp);
  for (i=1;i<=m;i++) c[i]=1e9;
  for (i=1;i<=n;i++)
  {
   k=a[i].se;
   for (j=min(i-1,m);j>=1;j--) k+=c[j];
   if (i<=m)c[i]=a[i].se; else
   if (a[i].se>c[1]) c[1]=a[i].se;
   b[a[i].th]=k;
   sort(c+1,c+m+1);
  }
  for (i=1;i<=n;i++) cout << b[i] << " ";
  return 0;
}