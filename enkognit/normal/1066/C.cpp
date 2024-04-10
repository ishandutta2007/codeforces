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

ll n,m,i,j,x,k,l1,r1,o,p;
ll l[200002],r[200002];

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   char c;
   cin >> c >> x;
   if (c=='L')
   {
    l1++;l[x]=l1;
   }else
   if (c=='R')
   {
    r1++,r[x]=r1;
   }else
   {
    if (l[x]==0) cout << min(r1-r[x],l1+r[x]-1) << "\n"; else cout << min(l1-l[x],r1+l[x]-1) << "\n";
   }
  }
  return 0;
}