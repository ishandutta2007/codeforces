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

ll n,p=0,k,m,i,j,o,l,ans,x,y,q;ll a[200001];vector<pll> b;
pll v[1000001];
string s;
ll t[100001];
vector <ll> c[100001];

bool comp(pll x,pll y)
{
 return x.fi>y.fi || (x.se<y.se && x.fi==y.fi);
}

int main()
{
  //freopen("C.in","r",stdin);
  //freopen("C.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  t[1]=1;
  for (i=2;i<=n;i++) t[i]=(i^t[i-1]);
  cin >> x;
  q=x;
  for (i=2;i<=n;i++)
  {
   cin >> x;
   q=q^x;
   for (j=0;j<n/i;j++) q=q^t[i-1];
   q=q^t[n%i];
  }
  cout << q;
  //for (j=0;j<n;j++) cin >> a[i];
  return 0;
}