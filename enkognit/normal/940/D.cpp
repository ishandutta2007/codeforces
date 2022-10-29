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
#define sqr(a) ((a)*(a))
#define ldl long double
/**/
using namespace std;

ll n,m,l=-1e9+2,r=1e9-2,i,j,k;
ll a[100001];
string s;

int main()
{
  //freopen("moocast.in","r",stdin);
  //freopen("moocast.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> a[i];
  }
  cin >> s;
  for (i=4;i<s.len;i++)
   if (s[i]!=s[i-1])
  {
   if (s[i]=='1')
   l=max(l,max(max(max(a[i+1],a[i]),a[i-1]),max(a[i-2],a[i-3]))+1); else
   if (s[i]=='0')
   r=min(r,min(min(min(a[i+1],a[i]),a[i-1]),min(a[i-2],a[i-3]))-1);
  }
  cout << l << " " << r;
  return 0;
}