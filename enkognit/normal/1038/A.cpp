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

using namespace std;

ll n,i,j,p,x,y,m,l=0,l1,r,k=1e9;string s;
map <char,ll> c;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> s;
  for (i=0;i<n;i++)
  {
   if (s[i]-64<=m) c[s[i]]++;
  }
  for (i=0;i<m;i++)
   k=min(c['A'+i],k);
  cout << k*m;
  return 0;
}