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

ll n,k,m,i,x,l;ll a[300001];
string s;
map <ll,vector<ll> > t;
vector <ll> v;

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
   l+=a[i];
   if (t[a[i]].size()<2)t[a[i]].pb(i+1);
  }
  for (i=0;i<n;i++)
  {
   ll j=0;
   if (t[(l-a[i])/2].size()>0 && (l-a[i])%2==0)
   {while (j<t[(l-a[i])/2].size() && t[(l-a[i])/2][j]==i+1) j++;
   if (j<t[(l-a[i])/2].size()){k++;v.pb(i+1);}}
  }
  cout << k << "\n";
  for (i=0;i<k;i++) cout << v[i] << " ";
  return 0;
}