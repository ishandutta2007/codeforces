#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

const ll MOD=998244353;

ll n,m,j,l,r,k,ans,a[500001];
vector<pll> c[200001];
vector <string> v;
string s;
set<ll> st;
map<ll,ll> t;

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ll t;
  cin >> t;
  while (t)
  {
      t--;
      string d="";
      cin >> n;
      cin >> s;
      if (s.size()>2)
      {
          cout << "YES\n";
          cout << 2 << "\n";
          cout << s[0] << " ";
          s.erase(0,1);
          cout << s;
          cout << "\n";
      }else
      if (s.size()==2)
      {
          if (s[0]<s[1]) cout << "YES\n 2\n" << s[0] << " " << s[1] << "\n";else
          cout <<"NO\n";
      } else cout << "NO\n";
  }
}