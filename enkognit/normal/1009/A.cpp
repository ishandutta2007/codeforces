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

ll n,m,k,kn,kw,ke,ks,l,r,i,j,w,x,y,p,b[200001],c[200001];
bool t;
string s,d;

//struct thll{ll fi,se,th;};

ll a[200001];



int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=1;i<=m;i++) cin >> b[i];
  i=0;j=1;
  while (i<n && j<=m)
  {
   i++;
   if (a[i]<=b[j]) j++;
  }
  cout << j-1;
  return 0;
}