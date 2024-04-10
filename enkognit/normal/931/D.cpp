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

int n,m,l=0,i,j,k,ka[100001];
vector<int> a[100001];
bool f[100001];

int main()
{
  //freopen("chronicle.in","r",stdin);
  //freopen("chronicle.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n;
  for (i=1;i<=n-1;i++)
  {
   cin >> m;
   ka[m]++;
   if (ka[m]==1) a[m].pb(0);
   a[m].pb(i+1);
  }
  queue <pair<int,int> > bf;
  bf.push(mp(1,1));
  while (!bf.empty())
  {
   int x=bf.fr.fi,y=bf.fr.se;
   bf.pop();
   f[y]=(f[y]+1)%2;
   if (y>l) l=y;
   for (int i=1;i<=ka[x];i++)
   bf.push(mp(a[x][i],y+1));
  }
  for (i=1;i<=l;i++) k+=f[i];
  cout << k;
  return 0;
}