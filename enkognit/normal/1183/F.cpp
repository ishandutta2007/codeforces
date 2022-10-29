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

const ll MOD=1e9+7;
ll n, m, k, q, l, r, a[300005], p[300005], i, j;
bool t[1000001];

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  ll q;
  cin >> q;
  while (q--)
  {
      ll n;
      cin >> n;
      bool t[200001]={};
      vector <ll> v={};
      for (int i = 0; i < n; i++)
      {
          ll x;
          cin >> x;
          if (!t[x]) v.pb(x);
          t[x]=1;
      }
      sort(v.begin(),v.end());
      ll m=v.size()-1;
      if (v.size()==1) {cout << v[m] << "\n";continue;}
      if (v[m]%v[m-1])
      {
          ll ans=v[m]+v[m-1];
          //cout << v[m] << " " << v[m-1] << "\n";
          for (int i = m-2; i > -1; i--)
              if (v[m]%v[i] && v[m-1]%v[i]) {ans+=v[i];break;}
          cout << ans << "\n";
      }else
      {
          ll ans1=v[m], ans2=v[m-1], o1=0, o2=0;
          for (int i = m-2; i > -1; i--)
          {
              if (o1==0 && v[m]%v[i]) ans1+=v[i], o1=v[i];else
              if (o1!=0 && o1%v[i] && v[m]%v[i]) {ans1+=v[i];break;}
          }
          for (int i = m-2; i > -1; i--)
          {
              if (o2==0 && v[m-1]%v[i]) ans2+=v[i], o2=v[i];else
              if (o2!=0 && o2%v[i] && v[m-1]%v[i]) {ans2+=v[i];break;}
          }
          cout << max(ans1,ans2) << "\n";
      }
  }
  return 0;
}