#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std;

ll n,m,i,j,l,k;
ll a[6][6];
bool tt[6];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 for (i=1;i<=5;i++)
  for (j=1;j<=5;j++)
   cin >> a[i][j];
 for (i=1;i<=5;i++)
  for (j=1;j<=5;j++)
   for (int u=1;u<=5;u++)
    for (int g=1;g<=5;g++)
     for (int h=1;h<=5;h++)
      if (i!=j && i!=u && i!=g && i!=h && j!=u && j!=u && j!=g && j!=h && u!=g && u!=h && g!=h)
      l=max(l,2*(a[h][g]+a[g][h])+2*(a[u][g]+a[g][u])+a[j][u]+a[u][j]+a[i][j]+a[j][i]);
 cout << l << "\n";
 return 0;
}