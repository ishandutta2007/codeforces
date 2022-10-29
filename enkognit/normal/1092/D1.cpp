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

ll n,m,i,j,k,l,a[200001],b[200001],c[200001];


int main()
{
  //freopen("cipher.in","r",stdin);
  //freopen("cipher.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  vector <ll> v;
  for (i=0;i<n;i++)
  {
   ll x;
   cin >> x;
   x%=2;
   if (v.size()==0 || v[v.size()-1]!=x) v.pb(x); else v.erase(v.end()-1);
  }
  if (v.size()<2) cout << "YES\n"; else cout << "NO\n";
  return 0;
}