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

ll n,k,m,i,j,o,z,l,p,ans,x,y,a[200002],b[200002];

bool t[101];

ll binpow(ll p,ll o)
{
 ll l=0,y=1;
 while (l<o)
 {
  if (l>0 && l%2==0 && o/2>=l) l*=2,y*=y; else l++,y*=2;
 }
 return p*y;
}

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> b[i];
   ll o=0;
   for (j=0;j<b[i];j++) {cin >> x;z=max(z,x);o=max(o,x);}
   a[i]=o;
  }
  for (i=0;i<n;i++)
  {
   l+=(z-a[i])*b[i];
  }
  cout << l;
  return 0;
}