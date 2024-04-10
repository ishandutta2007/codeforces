#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll i,j,k,l,n,m,a[1001][1001];
bool t[1001];
string s,s1;

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  s1="aeiou13579";
  cin >> s;
  for (i=0;i<s.length();i++)
   if (s1.find(s[i])!=-1) k++;
  cout << k;
  return 0;
}