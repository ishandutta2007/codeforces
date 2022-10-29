#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>

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

int n,p=0,k,m,i,j,o,l,ans,x,y;
map <string,map<ll,ll> > t;
vector <ll> v[100001];



ll binpow(ll p,ll o)
{
 ll l=0,y=1;
 while (l<o)
 {
  if (l>0 && l%2==0 && o/2>=l) l*=2,y*=y; else l++,y*=2;
 }
 return p*y;
}

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
   string s,d;
   cin >> s >> d;
   ll u2=0,r=0;
   string u1;
   for (int j=0;j<d.size();j++)
   u2|=binpow(1,d[j]-'a');
   for (int j=0;j<s.size();j++)
    if (d.find(s[j])==string::npos) r=j+1;
   u1=s.substr(0,r);
   if (!t[u1][u2]) o++,v[o].pb(i+1),t[u1][u2]=o; else v[t[u1][u2]].pb(i+1);
  }
  cout << o << "\n";
  for (i=1;i<=o;i++)
  {
   cout << v[i].size() << " ";
   for (j=0;j<v[i].size();j++) cout << v[i][j] << " ";
   cout << "\n";
  }
  return 0;
}