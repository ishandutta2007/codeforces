#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005

int sum[N][3][3],a[N],b[N],i,j,m,n,p,k;
char c[N];
long long ans;
int main()
{ 
   scanf("%s",c); n=strlen(c);
   for (i=1;i<=n;++i)if (c[i-1]=='R') a[i]=1; else if (c[i-1]=='B') a[i]=2;
   scanf("%s",c); m=strlen(c);
   for (i=1;i<=m;++i)
   {
     if (c[i-1]=='R') b[i]=1; else if (c[i-1]=='B') b[i]=2;
     for (j=0;j<=2;++j)
       for (k=0;k<=2;++k)
          sum[i][j][k]=sum[i-1][j][k];
          sum[i][b[i-1]][b[i]]++;
   }
   int l=1,r=1;
   for(i=1;i<=n;++i)
   {
   	  for (;r<m&&b[r]!=a[i];++r);
   	  ans+=r-l+1;
   	  if (l<=m&&i>1&&a[i]!=a[i-1]) ans-=sum[r][a[i]][a[i-1]]-sum[l][a[i]][a[i-1]];
   	  if (l<=m&&b[l]==a[i]) ++l;
   	  if (r<m&&b[r]==a[i]) ++r;
   }
   printf("%I64d\n",ans);
}