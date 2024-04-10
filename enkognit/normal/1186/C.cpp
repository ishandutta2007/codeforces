#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define leng length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, p1, p2, q, l, r, a[1000005], kol[1000005], i, j;

string s, d;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> s;
  cin >> d;
  s=' '+s;
  ll n=s.size()-1;
  ll p=0;
  for (int i = 0; i < d.size(); i++) if (d[i]=='1')p++;
  for (int i = 1; i <= n; i++) {a[i]=a[i-1];if (s[i]=='1') a[i]++;}
  ll m=d.size(), ans=0;
  for (int i = 1; i <= n-m+1; i++)
  {
      ll o=a[i+m-1]-a[i-1];
      ans+=(abs(o-p)%2+1)%2;
  }
  cout << ans;
  return 0;
}