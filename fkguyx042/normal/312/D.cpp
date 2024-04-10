#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100001],i,j,m,n,p,k,t[100001];
long long cost[100001],f[101][100001],s[100001],que[100001];
long long up(int x,int y) { return f[i-1][x]+s[x] - (f[i-1][y]+s[y]);}
long long down(int x, int y) {return x-y;}
int main()
{ scanf("%d%d%d",&n,&m,&p);
  for (i=2;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
  for (i=1;i<=m;i++)
  {scanf("%d%d",&k,&t[i]);
    t[i]-=a[k];
}
  sort(t+1,t+m+1);
for (i=1;i<=m;i++) s[i]=s[i-1]+t[i];
memset(f,63,sizeof(f)); f[0][0]=0;
if (p>=m) { printf("0\n"); return 0;}
for (i=1;i<=p;i++)
 {  int l=1,r=1; que[1]=0;
    for (j=1;j<=m;j++)
     { while (l<r&&up(que[l+1],que[l])<=1ll*t[j]*down(que[l+1],que[l])) l++;
       f[i][j]=f[i-1][que[l]]+t[j]*(j-que[l])+s[que[l]]-s[j];
       while (l<r&&up(que[r],que[r-1])*down(j,que[r])>up(j,que[r])*down(que[r],que[r-1])) r--;
       que[++r]=j;
 }
}
printf("%I64d\n",f[p][m]);
}