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

ll n,m,k=0,a[200001],ans,l;
string s;


int main()
{
  //freopen("fence.in","r",stdin);
  //freopen("fence.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (int i=0;i<n;i++)
  {
      ll x;
      cin >> x;
      bool t=0;
      //if (x==179) cout << 360 << "\n"; else
      for (ll j=3;j<361;j++)
        if (x*j%180==0 && x<=180*(j-2)/j) {cout << j << "\n";t=1;break;}
        if (!t) cout << -1 << "\n";
  }
  return 0;
}