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
  cin >> n;
  ll l=1e9;
  for (int i = 1; i*i <= n; i++)
  {
      l=min(i+n/i+(n%i>0),l);
  }
  cout << l;
}