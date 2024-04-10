#include <bits/stdc++.h>
#include <iostream>

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

const ll N=200001;

ll x,y,n,m,i,j,k,l;


int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> x >> y >> k;
   if (max(x,y)>k) cout << -1 << "\n"; else
   {
    ll e=min(x,y)+(max(x,y)-min(x,y))-(max(x,y)-min(x,y))%2;
    e+=(k-max(x,y));
    if ((k-max(x,y))%2==1 && (max(x,y)-min(x,y))%2==0) e-=2;
    cout << e << "\n";
   }
  }
  return 0;
}