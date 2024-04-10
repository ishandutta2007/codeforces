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
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit

using namespace std;

ll n,k,m,i,j,o,l,r,ans,x,y,a[1000001];
//vector<ll> b[1000001];

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> l >> r;
   short p=0,u=0;
   if (l%2==0) p=-1; else p=1;
   if (r%2) u=-1; else u=1;
   cout << p*(r-l+1)/2+u*r*((r-l+1)%2) << "\n";
  }
  return 0;
}