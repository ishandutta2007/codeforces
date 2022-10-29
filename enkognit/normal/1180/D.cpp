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

ll n, m, k, l, r;
pll ans[500008];
vector <ll> v, z;
vector <pll> p;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  cin >> n >> m;
  for (int it = 0; it < n/2; it++)
  {
      if (it%2==0)
      {
          for (int i = 1; i <= m; i++)
          {
              cout << it+1 << " " << i << "\n";
              cout << n-it << " " << m-i+1 << "\n";
          }
      }
       else
      {
          for (int i = 1; i <= m; i++)
          {
              cout << it+1 << " " << m-i+1 << "\n";
              cout << n-it << " " << i << "\n";
          }
      }
  }
  if (n%2)
  {
      for (int i = 1; i <= m/2; i++)
      {
          cout << n/2+1 << " " << i << "\n";
          cout << n/2+1 << " " << m-i+1 << "\n";
      }
      if (m%2) cout << n/2+1 << " " << m/2+1 << "\n";
  }
  return 0;
}