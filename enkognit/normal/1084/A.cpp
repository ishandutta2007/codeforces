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
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

ll binpow(ll n,ll p,ll r)
{
 ll l=1,o=0;
 while (o<p)
 {
  if (o*2<=p && o>0) l*=l,l%=r,o*=2; else l*=n,l%=r,o++;
 }
 return l;
}

ll n,m,k,a[1001];

int main()
{
  //freopen("disease.in","r",stdin);
  //freopen("disease.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  int i;
  for (i=1;i<=n;i++)
  {
   cin >> a[i];
  }
  ll l=1e9;
  for (i=1;i<=n;i++)
  {
   ll p=0;
   for (int j=1;j<=n;j++) p+=a[j]*((j-1)*2+(abs(i-j)+i-1)*2);
   l=min(l,p);
  }
  cout << l;
  return 0;
}