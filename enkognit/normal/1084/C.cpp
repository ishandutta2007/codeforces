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

ll n,m,k=0;
string s;

int main()
{
  //freopen("disease.in","r",stdin);
  //freopen("disease.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> s;
  vector <ll> a(100003);
  s=s+'b';
  k=0;ll o=0;
  for (int i=0;i<s.size();i++)
   if (s[i]=='a')k++;else if (s[i]=='b')if (k>0) a[o++]=k,k=0;
  ll l=0;

  for (int i=0;i<o;i++) l+=a[i]*(l+1),l%=(ll)(1e9+7);
  cout << l;
  return 0;
}