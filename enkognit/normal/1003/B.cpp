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

ll n,m,l,i,j,x,y;long double k,dp[50001],a[50001];
string s;bool tt;

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  ll j=min(m,n);
  if (m<=n)
  for (i=1;i<=j;i++)
  {
   cout << "0";
   n--;
   if (k==1)
   {
    for (int u=1;u<=n;u++) cout << "0";
    for (int u=1;u<=m;u++) cout << "1";
    exit(0);
   } else
   if (k==2)
   {
    for (int u=1;u<=m;u++) cout << "1";
    for (int u=1;u<=n;u++) cout << "0";
    exit(0);
   } else
   {
    cout << "1";
    m--;
    k-=2;
   }
  } else
  for (i=1;i<=j;i++)
  {
   cout << "1";
   m--;
   if (k==1)
   {
    for (int u=1;u<=m;u++) cout << "1";
    for (int u=1;u<=n;u++) cout << "0";
    exit(0);
   } else
   if (k==2)
   {
    for (int u=1;u<=n;u++) cout << "0";
    for (int u=1;u<=m;u++) cout << "1";
    exit(0);
   } else
   {
    cout << "0";
    n--;
    k-=2;
   }
  }
  return 0;
}
/**/