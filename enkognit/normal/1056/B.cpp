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

ll n,p=0,k,m,i,j,o,l,ans,x,y,a[100001],b[10001];
string s,d;
map <ll,ll> t;
vector <ll> c[100001];

bool comp(ll i,ll j)
{
 return a[i]>a[j];
}

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  if (m==1) {cout << n*n;exit(0);}
  ll l=n/m;
  for (i=0;i<m;i++) a[(i*i)%m]+=l;
  ll r=n%m;
  for (i=1;i<=r;i++) a[(i*i)%m]++;
  ans=a[0]*a[0];
  for (i=1;i<m;i++)
  {
   ans+=a[i]*a[m-i];
  }
  cout << ans;
  return 0;
}