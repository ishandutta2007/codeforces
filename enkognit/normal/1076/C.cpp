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

using namespace std;

ll n,m,i,j,k,l=0,x,y,h,r,o,p=0,d[500001],a[500001];
string s;


int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   ld x;
   cin >> x;
   cout.precision(9);
   if (x==0) cout <<fixed<< "Y " << 0.0 <<" "<< 0.0 << "\n"; else
   if (x==4) cout <<fixed<< "Y " << 2.0 <<" "<< 2.0 << "\n";
   if (x==4 || x==0) continue;
   ld l=1,r=2;bool e=0;
   while (l<r)
   {
    ld w=(l+r)/2,u=x-w;
    if (abs(w*u-x)<1e-10) {e=1;cout <<fixed<< "Y " << u << " " << w << "\n";break;}
    if (w*u>x) r=w; else l=w;
   }
   if (!e) cout << "N\n";
  }
  return 0;
}
/*l=1;
  i=2;
  j=n;r=1;
  for (i=2;i<=n;i++)
  {
   j=n;
   if (j%i==0) l++;
   while (j%i==0) j/=i;
  }
  cout << l;*/