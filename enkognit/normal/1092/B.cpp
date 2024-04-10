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

vector<ll> v[(ll)1e6];

int main()
{
  //freopen("cipher.in","r",stdin);
  //freopen("cipher.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ll n,i,j,m,k,l,a[10001];
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  ll ans=0;
  for (int i=1;i<n;i+=2)
   ans+=a[i]-a[i-1];
  cout << ans;
  return 0;
}