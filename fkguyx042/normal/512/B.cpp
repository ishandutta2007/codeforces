#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,f[301][100001];
int Prime[10000001],cost[100001],a[3001];
int gcd(int x,int y) { return y==0?x:gcd(y,x%y); }
void Min(int &x,int y)
{if (x>y) x=y; }
int main()
{   scanf("%d",&n);
     for (i=1;i<=n;i++) scanf("%d",&a[i]);
     for (i=1;i<=n;i++) scanf("%d",&cost[i]);
     for (i=1;i<=n;i++)
       for (j=1;j*j<=a[i];j++)
         if (a[i]%j==0) Prime[++Prime[0]]=j,Prime[++Prime[0]]=a[i]/j;
    sort(Prime+1,Prime+Prime[0]+1);
    Prime[0]=unique(Prime+1,Prime+Prime[0]+1)-(Prime+1);
    memset(f,60,sizeof(f));
    for (i=1;i<=n;i++)
      f[i][lower_bound(Prime+1,Prime+Prime[0]+1,a[i])-Prime]=cost[i];
    for (i=1;i<n;i++)
      for (j=1;j<=Prime[0];j++)
        if (f[i][j]<INF)
      {    Min(f[i+1][lower_bound(Prime+1,Prime+Prime[0]+1,gcd(Prime[j],a[i+1]))-Prime],f[i][j]+cost[i+1]);
           Min(f[i+1][j],f[i][j]);
      }
    if (f[n][1]>=INF) printf("-1\n");
    else printf("%d\n",f[n][1]);
}