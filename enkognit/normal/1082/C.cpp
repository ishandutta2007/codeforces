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

ll n,p=0,k,m,i,j,o,l,ans,x,y,d[200001];vector<pll> b;
string s;
map <ll,pll> t;
vector <ll> c[100001];



int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> x >> y;
   b.pb(mp(y,x));
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  for (i=0;i<b.size();i++)
  {
   t[b[i].se].fi++;
   if (b[i].fi+t[b[i].se].se>0)
   d[t[b[i].se].fi]+=b[i].fi+t[b[i].se].se;
   t[b[i].se].se+=b[i].fi;
  }
  p=0;
  for (i=0;i<100002;i++)
  p=max(p,d[i]);
  cout << p;
  return 0;
}