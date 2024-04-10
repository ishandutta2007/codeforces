#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long
#define pb push_back
#define len length()

using namespace std;

ll n,m,i,j,k,l,r=0,a[101];
bool tt[101],t[101];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n >> m;
 for (i=1;i<=n;i++)
 {
  cin >> a[i];
  if (!t[a[i]]) {tt[i]=1;t[a[i]]=1;l++;}
 }
 if (l>=m)
 {
  cout << "YES\n";
  for (i=1;i<=n;i++)
  {
   if (tt[i]) {cout << i << " ";r++;}
   if (r==m) break;
  }
 }else
 cout << "NO";
 return 0;
}