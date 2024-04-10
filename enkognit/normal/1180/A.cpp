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

ll x,y,n,m,k,f,p;
map <ll,string> t;
vector <ll> v;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  cin >> n;
  if (n==1) cout << 1; else
  {
     ll ans=0;
     for (int i = 1; i < n*2; i+=2)
          ans+=i;
     for (int i = 1; i < n*2-1; i+=2) ans+=i;
     cout << ans;
  }
  return 0;
}