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

ll n,m,i,j,k,l,r;
string s[101],ss[101];
string tt[101];

bool comp(string s,string g)
{
 return s.len<g.len;
}

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> s[i];
  if (tt[s[i].len]!=s[i] && tt[s[i].len]!="") {cout << "NO\n";exit(0);} else tt[s[i].len]=s[i];
 }
 sort(s+1,s+n+1,comp);
 for (i=2;i<=n;i++)
  if (s[i].find(s[i-1])==string::npos) {cout << "NO\n";exit(0);}
 cout << "YES\n";
 for (i=1;i<=n;i++) cout << s[i] << "\n";
 return 0;
}