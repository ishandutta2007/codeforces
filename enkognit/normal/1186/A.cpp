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
ll n, m, k, q, l, r, a[1000005], kol[1000005], i, j;
map <ll, ll> t;
string s;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  if (n>min(m,k)) cout << "No\n"; else cout << "Yes\n";
  return 0;
}