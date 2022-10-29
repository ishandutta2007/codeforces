#include <bits/stdc++.h>
/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>
*/
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
/**/
using namespace std;

int n,m,l,i,j,k,w;
vector <int> c[10001];

int main()
{
  //freopen("chronicle.in","r",stdin);
  //freopen("chronicle.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (i=0;i<=n;i++) c[0].pb(i);
  while (1)
  {
   l++;
   c[l].pb(0);
   for (i=0;i<n/2;i++)
   {
    if ((m==c[l-1][i*2+1] || m==c[l-1][i*2+2])&&!(k==c[l-1][i*2+1] || k==c[l-1][i*2+2])) c[l].pb(m); else
    if (!(m==c[l-1][i*2+1] || m==c[l-1][i*2+2])&&(k==c[l-1][i*2+1] || k==c[l-1][i*2+2])) c[l].pb(k); else
    if (!(m==c[l-1][i*2+1] || m==c[l-1][i*2+2])&&!(k==c[l-1][i*2+1] || k==c[l-1][i*2+2])) c[l].pb(c[l-1][i*2+1]); else
    if ((m==c[l-1][i*2+1] || m==c[l-1][i*2+2])&&(k==c[l-1][i*2+1] || k==c[l-1][i*2+2]))
    {
     if (c[l-1].size()==3) cout << "Final!"; else cout << l;
     exit(0);
    }
   }
   n/=2;
  }
  return 0;
}