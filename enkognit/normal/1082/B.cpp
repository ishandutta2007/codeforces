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

ll n,p=0,k,m,i,j,o,l,ans,x,y,a[100001];vector<pll> b;
string s;
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
  cin >> n;
  cin >> s;
  s=s[0]+s;
  s+=' ';
  for (i=1;i<=n+1;i++)
  {
   if (s[i]=='G') l++;
   if (s[i]==s[i-1])  k++; else b.pb(mp(k,s[i-1]=='G')),k=1;
  }
  //b.pb(mp(1,0));
  for (i=0;i<b.size();i++)
  {
   if (b[i].se)p=max(p,b[i].fi+(b[i].fi<l));
   if (!b[i].se && b[i].fi==1 && i>0 && i<b.size()-1) p=max(p,b[i-1].fi+b[i+1].fi+(b[i-1].fi+b[i+1].fi<l));
  }
  cout << p;
  return 0;
}