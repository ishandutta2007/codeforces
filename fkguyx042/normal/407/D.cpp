#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,c[405][160005],ans;
int f[405][405],a[405][405],len;
int main()
{
     scanf("%d%d",&n,&m);
     for (i=1;i<=n;++i)
        for (j=1;j<=m;++j) scanf("%d",&a[i][j]);
     for (i=1;i<=n;++i)
     {
        for (len=1;len<=m;++len)
          for (j=1;j<=m-len+1;++j)
          {
               int r=j+len-1;
                 if (j==r) f[j][r]=max(f[j][r],c[j][a[i][j]]);
                 else 
                 {
                        f[j][r]=max(f[j][r],max(f[j][r-1],f[j+1][r]));
                        f[j][r]=max(f[j][r],max(c[r][a[i][j]],c[j][a[i][r]]));
                        if (a[i][j]==a[i][r]) f[j][r]=i;
                 }
                ans=max(ans,(i-f[j][r])*len);
          }
          for (j=1;j<=m;++j) c[j][a[i][j]]=i;
     }
     printf("%d\n",ans);
}