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

ll n,k,m,i,l,a[100001],b[100001];
string s,d;
ld x,y;
char c;

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=0;i<n;i++) cin >> b[i];
  if (a[0]==0 || (a[m-1]==0 && b[m-1]==0)) {cout << "NO\n";exit(0);}
  if (a[m-1]==1) {cout << "YES\n";exit(0);}
  bool u=0;
  for (i=m;i<n;i++) if (a[i] && a[i]==b[i]) {u=1;break;}
  if (u) cout << "YES\n"; else cout << "NO\n";
  return 0;
}