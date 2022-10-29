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

ll n,m,i,j,l,r,x,y,l1,l2,r1,r2;

int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> x >> y;
  cin >> l1 >> r1;
  cin >> l2 >> r2;
  if ((l1>x && l2>x && r1>y && r2>y) || (l1<x && l2<x && r1>y && r2>y) ||
      (l1>x && l2>x && r1<y && r2<y) || (l1<x && l2<x && r1<y && r2<y)) cout << "YES",0; else cout << "NO";
  return 0;
}