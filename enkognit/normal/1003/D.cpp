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

ll n,m,k,l=0,r,i,j,w,x,y,p;pll a[200001];
map<ll,ll> c;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++){cin >> w;c[w]++;}
  for (i=0;i<m;i++)
  {
   cin >> w;
   k=0;
   for (j=30;j>-1;j--)
   {
    l=1<<j;
    if (c[l]>0 && l<=w)
    {
     x=min(c[l],w/l);
     //cout << x << " ";
     w-=l*x;
     k+=x;
    }
    if (!w) break;
   }
   if (!w) cout << k << "\n"; else cout << -1 << "\n";
  }
  return 0;
}