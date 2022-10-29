#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,i,u,j,o,k,l,r;
bool t[1000001];
map<ll,ll> mp;
string s,d;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> k;
  for (i=0;i<k;i++)
  {
   ll x,y;
   cin >> x >> y;
   if (y<=x+m && y>=x-m && y>=(-x)+m && y<=(-x)-m+n+n) cout << "YES\n"; else cout << "NO\n";
  }
  return 0;
}