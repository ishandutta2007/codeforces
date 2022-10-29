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

ll n,p=0,k,b,m,i,j,o,l,ans,x,y,q,a[100001],dp[100001];
map <ll,ll> t;
string s;

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) {cin >> a[i];}
  sort(a,a+n);
  k=0;
  for (i=0;i<n;i++)
   if (a[i]>k)
  {
   m--;
   cout << a[i]-k << "\n";
   k+=a[i]-k;
   if (m==0) exit(0);
  }
  while (m) {cout << 0 << "\n";m--;}
  return 0;
}