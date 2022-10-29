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

ll n,p=0,k,m,i,j,o,l,ans,x,y,a[100001];
string s,d;
map <ll,ll> t;
vector <ll> v;

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> m;
   for (j=0;j<m;j++) {cin >> x;t[x]++;}
  }
  for (i=1;i<101;i++) if (t[i]==n) v.pb(i);
  for (i=0;i<v.size();i++) cout << v[i] << " ";
  return 0;
}