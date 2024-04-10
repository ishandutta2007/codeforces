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

ll n,m,a[10001],r,i,j,x,k,l,o,p;
vector <ll> v;bool t[10001];

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> r;
  for (i=0;i<n;i++) {cin >> t[i];}
  i=0;
  while (i<n)
   {
    bool u=0;
    for (int j=min(i+r-1,n-1);j>=max(i-r+1,(ll)0);j--) {if (t[j]) {i=j+r;l++;u=1;break;}}
    if (!u) {cout << -1;exit(0);}
   }
   cout << l;
  return 0;
}