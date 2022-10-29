#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>

using namespace std;

const ll N=1e18;

ll n,m,k,i;
string s,d;
vector <ll> a;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n >> m >> k;
 cin >> s;
 cin >> d;
 if (n<m)
 {for (i=0;i<k;i++)cout << 0 << "\n";exit(0); }
 for (i=0;i<s.size()-d.size()+1;i++)
  if (s[i]==d[0])
  {
   if (s.substr(i,d.size())==d) a.pb(i+1);
  }
 for (i=0;i<k;i++)
 {
  ll x,y,w,l=0;
  cin >> x >> y;
  w=upper_bound(a.begin(),a.end(),x-1)-a.begin();
  if (w==a.size()) {cout << 0 << "\n";continue;}
  for (int j=w;j<a.size() && a[j]<=y-d.size()+1;j++) l++;
  cout << l << "\n";
 }
 return 0;
}