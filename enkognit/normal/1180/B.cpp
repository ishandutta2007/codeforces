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

ll n, m, a[500008], k, l, r;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  cin >> n;
  ll k=0;
  for (int i = 0; i < n; i++)
  {
     cin >> a[i];
     if (a[i]>=0) a[i]=(-a[i])-1;
     if (a[i]==-1) k++;
  }
  if (n%2==1)
  {
     if (k==n) a[0]=0; else
     {
        ll m=n;
        a[n]=1e18;
        for (int i = 0; i < n; i++) if (a[m]>a[i] && a[i]!=-1) m=i;
        a[m]=(-a[m])-1;
     }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}