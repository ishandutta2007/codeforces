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

const ll MOD=998244353;

ll n,m,k=0,i,j,xx,yy,u,ans,x,y,q;
string s,d,p;
bool t[10001],tt[10001];


/*ll binpow(ll n,ll p,ll r)
{
 ll l=1,o=0;
 while (o<p)
 {
  if (o*2<=p && o>0) l*=l,l%=r,o*=2; else l*=n,l%=r,o++;
 }
 return l;
}*/

int main()
{
  //freopen("hps.in","r",stdin);
  //freopen("hps.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  while (n)
  {
   s=(char)(n%3+48)+s;
   n/=3;
  }
  while (m)
  {
   d=(char)(m%3+48)+d;
   m/=3;
  }
  while (s.size()<d.size())  s='0'+s;
  while (s.size()>d.size())  d='0'+d;
  for (i=0;i<s.size();i++)
  {
   ll o=d[i]-s[i];
   if (o<0) o+=3;
   p=(char)(o+48)+p;
  }
  ll l=0;
  if (p.size()>0){for (i=p.size()-1;i>=0;i--) l*=3,l+=p[i]-48;}
  cout << l;
  return 0;
}