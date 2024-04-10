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

ll n,m,k=0,i,j,u,ans;pll a[10],b[10];
string s,d;
vector <pll> v,g;



int main()
{
  //freopen("hex.in","r",stdin);
  //freopen("hex.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  for (i=0;i<3;i++) {cin >> a[i].fi >> a[i].se;b[i].fi=a[i].se;b[i].se=a[i].fi;}
  sort(a,a+3);
  sort(b,b+3);
  for (i=0;i<3;i++) {swap(b[i].fi,b[i].se);}

  for (i=a[0].fi;i<=a[2].fi;i++) v.pb(mp(i,b[1].se));

  for (i=min(a[0].se,b[1].se);i<=max(a[0].se,b[1].se);i++) if (i!=b[1].se) v.pb(mp(a[0].fi,i));

  for (i=min(a[1].se,b[1].se);i<=max(a[1].se,b[1].se);i++) if (i!=b[1].se) v.pb(mp(a[1].fi,i));

  for (i=min(a[2].se,b[1].se);i<=max(a[2].se,b[1].se);i++) if (i!=b[1].se) v.pb(mp(a[2].fi,i));

  for (i=b[0].se;i<=b[2].se;i++) g.pb(mp(a[1].fi,i));

  for (i=min(b[0].fi,a[1].fi);i<=max(b[0].fi,a[1].fi);i++) if (i!=a[1].fi) g.pb(mp(i,b[0].se));

  for (i=min(b[1].fi,a[1].fi);i<=max(b[1].fi,a[1].fi);i++) if (i!=a[1].fi) g.pb(mp(i,b[1].se));

  for (i=min(b[2].fi,a[1].fi);i<=max(b[2].fi,a[1].fi);i++) if (i!=a[1].fi) g.pb(mp(i,b[2].se));


  if (v.size()<g.size())
  {
   cout << v.size() << "\n";
   for (i=0;i<v.size();i++) cout << v[i].fi <<" "<< v[i].se << "\n";
  }
   else
  {
   cout << g.size() << "\n";
   for (i=0;i<g.size();i++) cout << g[i].fi <<" "<< g[i].se << "\n";
  }
  return 0;
}