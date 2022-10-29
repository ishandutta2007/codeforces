#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>

using namespace std;

ll n,m,i,j,x,y,z,k,l,r,o,p;

int main()
{
  //freopen("drying.in","r",stdin);
  //freopen("drying.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k >> l;
  l+=k;
  if (l>n) {cout << -1;exit(0);}
  if (m>n) {cout << -1;exit(0);}
  o=n/m;
  p=l/m+(l%m>0);
  if (p>o) {cout << -1;exit(0);} else cout << p;
  return 0;
}