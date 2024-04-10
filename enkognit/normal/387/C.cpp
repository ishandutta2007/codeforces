#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define ldl long double*/
/**/
using namespace std;

ll n,m,i,y,j,k,l;
string s1,s[100001],sd;

int main()
{
  //freopen("disease.in","r",stdin);
  //freopen("disease.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> s1;
  s1+=' ';
  for (i=0;i<s1.len;i++)
  {
   sd+=s1[i];
   if (s1[i+1]!='0') {l++;s[l]=sd;sd="";}
  }
  sd=s[1];
  k=1;
  for (i=2;i<l;i++)
  {
   if (sd.len>s[i].len || (sd.len==s[i].len && sd>=s[i])) k++; else k=1;
   sd+=s[i];
  }
  cout << k;
  return 0;
}