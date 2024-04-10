#include <bits/stdc++.h>
#include <string>

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

//struct thll{ll fi,se,th;};

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  ll n,m;
  cin >> n >> m;
  for (int j=0;j<m;j++)
  {
   ll x,y;
   cin >> x >> y;
   if ((x+y)%2==0) cout << ((x-1)*n+y+1)/2 << "\n"; else
   cout << ((x-1)*n+y+((x-1)*n+y)%2)/2+(n*n)/2+n*n%2 << "\n";
  }

  return 0;
}