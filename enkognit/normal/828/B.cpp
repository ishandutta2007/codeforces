#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n,m,i,j,k,l1=1000,l2,r1=1000,r2;
bool a[1001][1001];
string s;

int sqr(int h)
{
 return h*h;
}

int main()
{
 //freopen("papaya.in","r",stdin);
 //freopen("papaya.out","w",stdout);
 ios_base::sync_with_stdio(0);
 cin >> n >> m;
 for (i=1;i<=n;i++)
 {
  cin >> s;
  for (j=0;j<m;j++)
  {
   a[i][j+1]=(s[j]=='B');
   k+=a[i][j+1];
   if (a[i][j+1])
   {
    if (i<l1) l1=i;
    if (j+1<r1) r1=j+1;
    if (i>l2) l2=i;
    if (j+1>r2) r2=j+1;
   }
  }
 }
 if (k==0) cout << 1; else
 if (max(l2-l1+1,r2-r1+1)>min(n,m)) cout << -1; else
 cout << sqr(max(l2-l1+1,r2-r1+1))-k;
 cout << "\n";
 return 0;
}