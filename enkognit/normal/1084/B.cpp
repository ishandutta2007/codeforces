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
  ll s;
  cin >> n >> s;
  ll l=1e9,p=0;
  for (int i=0;i<n;i++)
  {
   cin >> a[i];
   l=min(l,a[i]);
   p+=a[i];
  }
  if (p<s) {cout << -1;exit(0);}
  ll k=0;
  for (int i=0;i<n;i++) k+=a[i]-l;
  if (k>=s) cout << l << "\n"; else
  {
   s-=k;
   cout << l-(s/n+(s%n>0));
  }
  return 0;
}