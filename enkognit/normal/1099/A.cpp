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

ll n,m,j,l,r,k,sum[100001],ans,len=0;

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ll w,h,h1,d1,d2,h2;
  cin >> w >> h;
  cin >> d1 >> h1;
  cin >> d2 >> h2;
  for (int i = h; i > 0; i--)
  {
      w+=i;
      if (i==h1) w=max(w-d1,0ll);
      if (i==h2) w=max(w-d2,0ll);
  }
  cout << w;
}