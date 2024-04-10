#include<cstdio>
#include<algorithm>
#define Mo 1000000007
using namespace std;
long long  f[1001],f3[1001],f4[1001];
long long f1[1001][1001];
long long f2[1001][2];
long long a[1001];
long long i,j,m,n,p,k,ans,now;
int main()
 {scanf("%I64d%I64d",&n,&m);
 if (n==m) { printf("1\n"); } else {
 f[1]=1; for (i=2;i<=n;i++) f[i]=(f[i-1]*2)%Mo;
   for (i=1;i<=m;i++)
    scanf("%I64d",&a[i]);
   sort(a+1,a+m+1);
   if (a[1]>1){ f2[++k][0]=1; f2[k][1]=a[1]-1;}
   for (i=2;i<=m;i++)
     if (a[i]-a[i-1]>1) {f2[++k][0]=f[a[i]-a[i-1]-1]; f2[k][1]=a[i]-a[i-1]-1; }
     if (a[m]<n) f2[++k][0]=1,f2[k][1]=n-a[m];
    f3[0]=1;
 for (i=0;i<=n;i++)
   {f1[0][i]=1;if (i>0) f3[i]=f3[i-1]+f1[0][i]; }
 for (i=1;i<=n;i++)
  { for (j=0;j<=n;j++)
      f1[i][j]=f3[j];
     for (j=1;j<=n;j++)
       f3[j]=(f3[j-1]+f1[i][j])%Mo;
}
now=f2[1][1];
ans=f2[1][0];
for (i=2;i<=k;i++)
  { ans=(ans*f2[i][0])%Mo*f1[now][f2[i][1]]%Mo;
      now+=f2[i][1];
}
printf("%I64d\n",ans);
}
return 0;
}