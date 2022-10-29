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

ll n,p=0,k,m,i,j,o,l,ans,x,y;pll a[200001];vector<pll> b;
pll v[1000001];
string s;
queue <pll> q;
map <ll,pll> t;
vector <ll> c[100001];



int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> a[i].fi;a[i].se=i+1;
  }
  sort(a,a+n);
  reverse(a,a+n);
  o=0;
  if (a[0].fi>0 && a[n-1].fi==1)
  {
   l++;
   b.pb(mp(a[n-1].se,a[0].se));
   a[0].fi--;
   n--;
  }
  for (i=0;i<n;i++)
   if (a[i].fi>0)
  {
   if (a[i].fi>1 || i==0)
   {
    l++;
    if (i>0)b.pb(mp(a[i-1].se,a[i].se));
    o++;
    if (i<n-1 && a[i+1].fi>1) a[i].fi--;
    if (a[i].fi+(i==0)>1)v[o]=mp(a[i].fi-1+(i==0),a[i].se);
   }else
   {
    while (v[o].fi<1 && o>0) o--;
    if (o==0) {cout << "NO\n";exit(0);}
    if (p<1) p++;
    //cout << o << "\n";
    v[o].fi--;b.pb(mp(a[i].se,v[o].se));
   }
  }
  cout << "YES " << l+p-1 << "\n";
  cout << b.size() << "\n";
  for (i=0;i<b.size();i++) cout << b[i].fi << " " << b[i].se << "\n";
  return 0;
}