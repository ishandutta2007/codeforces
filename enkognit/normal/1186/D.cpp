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
map <ll, ll> t;
vector <ll> v, z;
vector <pll> ans;
string s, b;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for (int it = 0; it < n; it++)
  {
      cin >> s;
      bool tt=0;
      if (s[0]=='-')
      {
          tt=1;
          s.erase(0,1);
      }
      ll o=0, z=0;
      for (int i = s.size()-5; i < s.size(); i++)
          if (s[i]!='0') z=1;
      for (int i = 0; i < s.size(); i++)
          if (s[i]=='.') break; else
      {
         o*=10;
         o+=s[i]-'0';
      }
      if (!z)
      {
          if (tt) ans.pb(mp(o,2)),p1+=o;else ans.pb(mp(o,3)),p2+=o;
      }else
      if (tt)
      {
          p1+=o;
          ans.pb(mp(o,1));
      }else
      {p2+=o;ans.pb(mp(o,0));}
      //cout << o << "\n";

  }
  ll r=p2-p1;
  //cout << p2 << " " << p1 << "\n";
  //cout << r << "\n";
  for (int i = 0; i < n; i++)
  {
      if (ans[i].se==0 && r<0) r++, ans[i].fi++; else
      if (ans[i].se==1 && r>0) r--, ans[i].fi++;
      //cout << ans[i].fi << " : " << r << "\n";
  }
  if (r!=0) cout << -1; else
  for (int i = 0; i < n; i++)
  {
    //cout << ans[i].se << "-";
     if (ans[i].se==1 || ans[i].se==2) cout << -ans[i].fi << "\n"; else cout << ans[i].fi << "\n";
  }
  return 0;
}