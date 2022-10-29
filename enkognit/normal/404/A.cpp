#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define len length()

using namespace std;

int n,m,i,z,j,k,a[1001][1001],l=0;
bool t[100001];
string s[1001];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (int i=1;i<=n;i++)
 {
  cin >> s[i];
 }
 char c1=s[1][0],c2=s[1][1];
 if (c1==c2) cout << "NO" << "\n",exit(0);
 for (i=1;i<=n;i++)
  for (j=0;j<n;j++)
 {
  if (i-1==j || j==n-i)
  {
   if (s[i][j]!=c1) cout << "NO" << "\n",exit(0);
  } else
  if (s[i][j]!=c2) cout << "NO" << "\n",exit(0);
 }
 cout << "YES" << "\n";
 return 0;
}