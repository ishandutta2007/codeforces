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

using namespace std;

ll n,m,i,j,x,y,z,k,l,o,p;vector <ll> a,b;
bool u;

int main()
{
  //freopen("cowart.in","r",stdin);
  //freopen("cowart.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  if (n>m) {swap(n,m);u=1;}
  l=0;ll o=0;
  while (l+o+1<=n+m)
  {
   o++;
   l+=o;
  }
  for (i=o;i>0;i--)
   if (n-i>=0) {a.pb(i);n-=i;} else if (m-i>=0){m-=i;b.pb(i);}
  if (u)
  {
   cout << b.size() << "\n";
   for (int i=0;i<b.size();i++) cout << b[i] << " ";
   if (b.size()>0)cout << "\n";
   cout << a.size() << "\n";
   for (int i=0;i<a.size();i++) cout << a[i] << " ";
  }else
  {
   cout << a.size() << "\n";
   for (int i=0;i<a.size();i++) cout << a[i] << " ";
   if (a.size()>0)cout << "\n";
   cout << b.size() << "\n";
   for (int i=0;i<b.size();i++) cout << b[i] << " ";
  }
  return 0;
}