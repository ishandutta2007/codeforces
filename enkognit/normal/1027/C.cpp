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

//struct thll{ll fi,se,th;};
vector <ll> b;
map <ll,ll> a;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  ll n,m;
  cin >> n;
  for (ll i=0;i<n;i++)
  {
   long double o=5e18;pll w=mp(0,0);
   cin >> m;
   a.clear();
   b.clear();
   for (int j=0;j<m;j++)
   {
    ll c;
    cin >> c;if (m==4) cout << c << " ";
    a[c]++;
    if (a[c]==2) {a[c]=0;b.pb(c);}
   }
   if (m>4){
   sort(b.begin(),b.end());
   for (int  j=0;j<b.size()-1;j++)
   {
    long double x=b[j],y=b[j+1];
    long double l=(x+y)*2;
    l=l*l/x/y;
    if (l<o) {o=l;w=mp(x,y);}
   }
   cout << w.fi << " " << w.fi << " " << w.se << " " << w.se;}cout << "\n";
  }
  return 0;
}