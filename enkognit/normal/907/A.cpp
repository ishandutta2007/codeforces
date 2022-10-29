#include <bits/stdc++.h>

using namespace std;

int i,j,u,k,l,n,m;
string s1,s2;

int main()
{
  //freopen(".in","r",stdin);
  //freopen(".out","w",stdout);
  cin >> n >> m >> k >> l;
  if (l>k*2) {cout << -1;exit(0);}
  if (k>l*2) {cout << -1;exit(0);}
  if (l>=m) {cout << -1;exit(0);}
  i=min(k,l)*2;
  cout << n*2 << " " << m*2 << " " << i;
  return 0;
}