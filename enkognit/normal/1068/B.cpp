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
  cin >> n;
  l=1;
  if (n!=1) l++;
  i=2;
  j=n;
  while (i<=sqrt((ld)n))
  {
   if (!(n%i))
   {
    l++;
    if (n/i!=i) l++;
   }
   i++;
  }
  cout << l;
  return 0;
}
/*l=1;
  i=2;
  j=n;r=1;
  for (i=2;i<=n;i++)
  {
   j=n;
   if (j%i==0) l++;
   while (j%i==0) j/=i;
  }
  cout << l;*/