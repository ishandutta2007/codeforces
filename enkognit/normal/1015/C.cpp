#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n,m,k=0,l=0,r,i,j,w,x,y;pll a[100001];

map<char,int> t,f;
string s,d;

bool comp(pll x,pll y)
{
 if (x.fi-x.se>y.fi-y.se) return true; else return false;
}

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) {cin >>a[i].fi>>a[i].se;k+=a[i].fi;}
  sort(a,a+n,comp);
  if (k<=m) cout << l; else
  {for (i=0;i<n;i++)
  {
   k-=a[i].fi-a[i].se;
   l++;
   if (k<=m) break;
  }if (k<=m)cout << l; else cout << -1;}
  return 0;
}
/*cin >> n;
  cin >> s;cin >> d;
  for (i=0;i<n;i++) t[s[i]]++,f[d[i]]++;
  for (i=0;i<n;i++) if (t[s[i]]!=f[d[i]]) {cout << -1;exit(0);}
  for (i=0;i<n;i++)
  {
   k+=s.find(d[i],i)-i;
   s.erase(s.find(d[i],i),1);
   s.insert((char)d[i],i);

   cout << k << "\n";
  }
  cout << k;*/