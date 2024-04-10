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

int main()
{
  //freopen("chronicle.in","r",stdin);
  //freopen("chronicle.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n >> m;
  n=abs(n-m);
  i=1;
  while (n>0)
  {
   if (n>1) l+=2*i,n-=2; else l+=i,n--;
   i++;
  }
  cout << l;
  return 0;
}