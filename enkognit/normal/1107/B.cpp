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
map<char,vector<ll> > t;

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
      ll k,x;
      cin >> k >> x;
      cout << (k-1)*9+x << "\n";
  }
}
/*cin >> n >> m;
  for (int i = 0; i < n; i++)  cin >> a[i];
  for (int i = 0; i < n; i++)
  {
      char c;
      cin >> c;
      t[c].pb(a[i]);
  }
  ll ans=0;
  for (char i = 'a'; i <= 'z'; i++)
  {
      sort(t[i].begin(),t[i].end());
      for (int j = t[i].size()-1; j >= max(t[i].size()-m,(ll)0); j--) {ans+=t[i][j];cout << t[i][j] << "\n";}
  }
  cout << ans;*/