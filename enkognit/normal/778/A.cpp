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

using namespace std;

ll n,m,i,j,x,y,z,k,l,o,p,a[200001];
string s,d;

void rec(ll l,ll r)
{
 bool u=0;string q="";
 map<ll,bool> t;
 ll w=(l+r)/2,j=0;
 if (l+1==r) w++;
 for (int i=0;i<w;i++) {t[a[i]-1]=1;}
 for (int i=0;i<n;i++) if (!t[i]) q+=s[i];
 if (l==r) {cout << l;exit(0);}
 for (int i=0;i<m;i++)
 {
  while (j<n && (t[j] || s[j]!=d[i])) j++;
  if (j==n) {u=1;break;}j++;
 }
 //cout << l << " " << r <<" " << q << "\n";
 if (u) rec(l,w-1); else rec(w,r);
}

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> s;
  cin >> d;
  n=s.size();
  m=d.size();
  //cout << 1;
  for (int i=0;i<n;i++)
  {
   cin >> a[i];
  }
  rec(0,n-m);
  return 0;
}