#include <bits/stdc++.h>

using namespace std;

long long n,m,i,j;
string s[500001],b[500001];
char c;

int main()
{
  //freopen("ticket3.in", "r", stdin);
  //freopen("ticket3.out", "w", stdout);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> c;
   cin >> s[i];
  }
  b[n]=s[n];
  for (i=n-1;i>=1;i--)
  {
   j=0;
   if (s[i]>b[i+1])
   {while (s[i][j]<=b[i+1][j]) {b[i]+=s[i][j];j++;}} else b[i]=s[i];
  }
  for (i=1;i<=n;i++) cout << "#" << b[i] << endl;
  return 0;
}