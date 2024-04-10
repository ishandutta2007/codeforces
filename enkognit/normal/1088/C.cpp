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

ll n,p=0,k,b,m,i,j,o,l,ans,x,y,q,a[100001];
map <ll,ll> t;
string s;

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) {cin >> a[i];}
  o=1;
  k=2e5;
  l=0;
  for (i=n-1;i>=0;i--)
   if ((a[i]+l)%k!=i+1)
   {
    o++;//cout << "1 " << i+1 << " " << 2e5-(a[i]+l)%k+i+1 << "\n";
    l+=2e5-(a[i]+l)%k+i+1;
   }
  cout << o << "\n";
  k=2e5;
  l=0;
  for (i=n-1;i>=0;i--)
   if ((a[i]+l)%k!=i+1)
   {
    cout << "1 " << i+1 << " " << 2e5-(a[i]+l)%k+i+1 << "\n";
    l+=2e5-(a[i]+l)%k+i+1;
   }
   cout << 2 << " " << n << " " << 2e5 << "\n";
  return 0;
}