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
ll n, m, k, ans, q, l, r, i, j, z[1000005];
bool t[1000001];
vector <ll> v[30], c[100001];
string s, d;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
      v[s[i]-'a'].pb(i+1);
  cin >> m;
  while (m--)
  {
      cin >> s;
      for (int i = 0; i < 26; i++) z[i]=-1;
      for (int i = 0; i < s.size(); i++)
          z[s[i]-'a']++;
      ll ans=0;
      for (int i = 0; i < 26; i++) if (z[i]>=0) ans=max(ans,v[i][z[i]]);
      cout << ans << "\n";
  }
  return 0;
}