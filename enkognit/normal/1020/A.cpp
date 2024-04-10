#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sp system("pause")

using namespace std;

const ll N=1e18;

ll n,m,k,l,a,b,x,y,w,r;
bool t[10001];

int main()
{
 //freopen("cows.in","r",stdin);
 //freopen("cows.out","w",stdout);
 cin >> n >> m >> a >> b >> k;
 for (int i=0;i<k;i++)
 {
  cin >> x >> y >> l >> r;
  ll u=abs(x-l);
  if (x==l || (y>=a && y<=b)) u+=abs(y-r); else
  if (y<a) u+=a-y+abs(a-r); else
  if (y>b) u+=y-b+abs(b-r);
  cout << u << "\n";
 }
 return 0;
}