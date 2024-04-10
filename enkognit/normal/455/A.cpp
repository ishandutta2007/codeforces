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

const ll N=1e5*(1e5+1)/2;

ll n,p=0,k,b,m,i,j,o,l,ans,x,y,q,a[100005],dp[100001];
vector <ll> v;
string s;

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n;
  //for (i=0;i<1e5+1;i++) a[i]=0,dp[i]=0;
  for (i=0;i<n;i++)
  {
   cin >> x;
   a[x]+=x;
  }
  ll u=0;l=a[1];dp[1]=a[1];
  p=dp[1];
  for (i=2;i<=100000;i++)
  {
   dp[i]=u+a[i];
   swap(u,l);
   l=max(u,dp[i]);
   p=max(p,dp[i]);
   //if (a[i]) cout << p;
  }
  cout << p;
  return 0;
}