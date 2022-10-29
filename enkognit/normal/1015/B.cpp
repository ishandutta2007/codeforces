#include <bits/stdc++.h>
#include <string>

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

ll n,m,k=0,l=0,r,i,j,w,x,y,a[100001];
map<char,ll> t,f;
vector <ll> b;
string s,d;

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n;
  cin >> s;
  cin >> d;
  for (i=0;i<n;i++) t[s[i]]++,f[d[i]]++;
  for (i=0;i<n;i++) if (t[s[i]]!=f[s[i]]) {cout << -1;exit(0);}
  for (i=0;i<n-1;i++)
  {
   ll u=0;
   for (u=i;u<n;u++) if (s[u]==d[i]) break;
   if (u==n) {cout << -1;exit(0);}
   for (int j=u-1;j>=i;j--) swap(s[j],s[j+1]),b.pb(j+1);
   k+=u-i;
  }
  cout << k << "\n";
  for (i=0;i<k-1;i++) cout << b[i] << " ";
  if (k>0)cout << b[k-1];
  return 0;
}