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

ll n,m,k,l,r,i,j,w,x,y,p,b[200001];
ll a[200001];
string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i];
  sort(a+1,a+n+1);
  //reverse(a+1,a+n+1);
  w=n-1;
  k=1;
  for (i=n-1;i>=1;i--)
  {
   //cout << 1;
   if (a[i]<a[i+1]) {if (w<=k){p+=w;break;}p+=k;w-=k;k=1;}else
   {
    k++;
    if (w>=i) w--;
   }
  }
  cout << p;
  return 0;
}