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
char c[300001];
vector <ll> v[200001];
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
  cin >> n >> m;
  for (int i = 0; i < n; i++)  cin >> a[i];
  ll k=0,ans=0;
  cin >> c[0];
  v[k].pb(a[0]);
  for (int i = 1; i < n; i++)
  {
     cin >> c[i];
     if (c[i]==c[i-1]) v[k].pb(a[i]); else k++,v[k].pb(a[i]);
  }
  //cout << k;
  for (int i = 0; i <= k; i++)
  {
      sort(v[i].begin(),v[i].end());
      //cout << v[i][v[i].size()-m];
      for (int j = v[i].size()-1; j >= max(v[i].size()-m,(ll)0); j--) ans+=v[i][j];
  }
  cout << ans;
}
/*char p='/';
  ll ans=0;
  for (int i = 0; i < n; i++)
  {
      if (c[i]==p)
      {
          if (v.size()<m) v.insert(a[i]),ans+=a[i]; else
          if (a[i]>*v.begin())
          {
              ans-=*v.begin();
              ans+=a[i];
              v.erase(v.begin());
              v.insert(a[i]);
          }
      } else
      {
          v.clear();
          v.insert(a[i]);
          p=c[i];
          ans+=a[i];
      }
  }
  cout << ans;*/