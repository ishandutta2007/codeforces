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

ll n,k,b,m,i,j,o,z,ans,x,y,a[100002];

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
  cin >> n >> m;
  k=1;
  ll p=1;
  cin >> a[0];
  for (i=1;i<n;i++)
  {
   cin >> a[i];
   if (a[i]==a[i-1])k=1; else k++;
   p=max(p,k);
  }
  cout << p;
  return 0;
}