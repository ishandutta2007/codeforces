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

using namespace std;

ll n,m,i,j,k,l,a[200001],b[1000001];
ll t[1000001];
string s;

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++)
  {
      b[a[i]]++;
      t[b[a[i]]]++;
      if (t[b[a[i]]]==n) cout << 1; else cout << 0;
  }
  return 0;
}