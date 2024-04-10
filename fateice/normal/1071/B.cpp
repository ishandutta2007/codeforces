#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,f[2010][2010],g[2010][2010],p;
char s[2010][2010],a[4010];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%s",&s[i][0]+1);
    for(i=1;i<=n;i++)
      f[i][0]=f[0][i]=1e9;
    f[0][1]=0;
    g[0][1]=1;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        {
         f[i][j]=min(f[i-1][j],f[i][j-1])+(s[i][j]!='a');
         if(f[i][j]<=m)
           p=max(p,i+j);
        }
    for(i=2;i<=p;i++)
      a[i]='a';
    k=p;
    for(i=max(1,k-n);i<k && i<=n;i++)
      if(f[i][k-i]<=m)
        g[i][k-i]=1;
    for(k=p+1;k<=2*n;k++)
      {
       a[k]='z';
       for(i=max(1,k-n);i<k && i<=n;i++)
         {
          j=k-i;
          if(g[i-1][j] || g[i][j-1])
            a[k]=min(a[k],s[i][j]);
         }
       for(i=max(1,k-n);i<k && i<=n;i++)
         {
          j=k-i;
          if((g[i-1][j] || g[i][j-1]) && a[k]==s[i][j])
            g[i][j]=1;
         }
      }
    printf("%s\n",&a[2]);
    return 0;
}