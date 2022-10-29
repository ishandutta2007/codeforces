#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
bitset<2001>f[2001];
int i,j,m,n,p,k;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    { scanf("%d",&p);
      f[i][j]=(p>0);
    }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      if (i!=k&&f[i][k]) f[i]|=f[k];
for (i=1;i<=n;i++) {for (j=1;j<=n;j++)
   if (!f[i][j]) break; if (j<=n) break; }
   if (i>n) printf("YES\n"); else printf("NO\n");
}