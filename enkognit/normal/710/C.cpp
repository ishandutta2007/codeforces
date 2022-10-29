#include <iostream>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std;

ll n,m,i,j,l,k;
ll a[50][50];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cin >> n;
 for (i=1;i<=n;i++) a[n/2+1][i]=1;
 l=1;
 for (i=1;i<=n/2;i++)
 {
  l++;
  for (int j=l;j<=n-l+1;j++) a[n/2+1-i][j]=1,a[n/2+1+i][j]=1;
 }
 l=0;k=-1;
 for (i=1;i<=n;i++)
  for (j=1;j<=n;j++)
   if (a[i][j]==0) {l+=2;a[i][j]=l;} else {k+=2;a[i][j]=k;}
 for (i=1;i<=n;i++)
 {
  for (j=1;j<n;j++) cout << a[i][j] << " ";
  cout << a[i][j] << "\n";
 }
 return 0;
}