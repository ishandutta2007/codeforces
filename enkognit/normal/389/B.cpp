#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define len length()

using namespace std;

int n,m,i,z,j,k,a[1001][1001],l=0;
bool t[1001][1001];
string s;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (int i=1;i<=n;i++)
 {
  cin >> s;
  for (j=0;j<n;j++) t[i][j+1]=s[j]=='#',l+=s[j]=='#';
 }
 if (l==0) cout << "YES" << "\n",exit(0);
 for (i=2;i<n;i++)
  for (j=2;j<n;j++)
   if (t[i][j]==1 && t[i-1][j]==1 && t[i+1][j]==1 && t[i][j-1]==1 && t[i][j+1]==1)
 {
  l-=5;
  t[i][j]=0;
  t[i-1][j]=0;
  t[i+1][j]=0;
  t[i][j-1]=0;
  t[i][j+1]=0;
 }
 if (l==0) cout << "YES" << "\n"; else cout << "NO" << "\n";
 return 0;
}