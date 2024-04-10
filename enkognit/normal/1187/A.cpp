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
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, ans, q, l, r, i, j, a[1000005];
bool t[1000001];
vector <ll> v, c[100001];
string s, d;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> q;
  while(q--)
  {
      cin >> n >> m >> k;
      ll p=m+k-n;
      cout << max(m,k)-p+1 << "\n";
  }
  return 0;
}