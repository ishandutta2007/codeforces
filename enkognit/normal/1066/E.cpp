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

ll n,m,i,j,x,k,l,o,p,a[200001];
string s,d;

ll bp(ll l,ll k)
{
 ll o=k,p=1;
 while (o>0)
 {
  o--;
  p=p*l%998244353;
 }
 return p;
}

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> s;
  cin >> d;
  j=1;
  for (i=0;i<=max(n,m);i++,j=j*2%998244353) a[i]=j;
  if (n<m) for (i=0;i<m-n;i++) s='0'+s;
  if (m<n) for (i=0;i<n-m;i++) d='0'+d;
  n=max(m,n);
  for (i=0;i<n;i++)
  {
   if (d[i]=='1') l++;
   if (s[i]=='1') k=(k+l*a[n-i-1])%998244353;
   //cout << k;
  }
  cout << k;
  return 0;
}