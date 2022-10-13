#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

int n,k,p[15],re,l,r,b[15],d[15];
vector <int> a;
map <int,int> mp;

void gen(int x)
{
  a.push_back(x); mp[x]=1;
  if (x>100000000) return;
  gen(x*10+4); gen(x*10+7);
}

int calc(int x)
{
  int r=0;
  while (r<int(a.size()) && a[r]<=x) r++;
  return r;
}

void solve(int b[],int k,int n)
{
  k--;
  for (int i=1;i<=n;i++)
  {
    int x=(k+p[n-i])/p[n-i],j=0;
    k%=p[n-i];
    while (x)
      if (!d[++j]) x--;
    b[i]=j; d[j]=1;
  }
}

int main()
{
  for (int i=0;i<13;i++) p[i]=(i?p[i-1]*i:1);
  gen(4); gen(7);
  sort(a.begin(),a.end());
  cin >> n >> k;
  if (n<13 && k>p[n]) 
  {
     puts("-1"); return 0;
  }
  for (r=1;r<13;r++)
    if (p[r]>=k) break;
  l=n-r;
  re=calc(l);
  solve(b,k,r);
  for (int i=1;i<=r;i++)
    if (mp[i+l] && mp[b[i]+l]) re++;
  cout << re << endl;      
}