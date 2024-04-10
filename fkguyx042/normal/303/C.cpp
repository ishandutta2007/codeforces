#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000005
using namespace std;
int fox[N],size[N],i,j,m,n,p,k,a[N],vis[N],k1,K;
struct Node{int ed,before;}s[10000001];
void add(int x,int y) 
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
int main()
{ scanf("%d%d",&n,&K);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  int C=(K+1)*K/2;
  sort(a+1,a+n+1);
  memset(vis,-1,sizeof(vis));
  for (i=1;i<=n;i++)
    for (j=1;j<i;j++)
      size[a[i]-a[j]]++;
  for (i=1;i<=n;i++)
    for (j=1;j<i;j++)
       if (size[a[i]-a[j]]<=C) add(a[i]-a[j],a[j]);
  for (i=n-K;i<=N;i++)
{    int sum=0;
   for (j=0;j*i<=N;j++)
   sum+=size[j*i];
    if (sum>C) continue;
    sum=0;
   for (j=0;j*i<=N;j++)
      for (k=fox[j*i];k;k=s[k].before)
         if (vis[s[k].ed]!=i)
      { vis[s[k].ed]=i;
        sum++;
        if (sum>k) break;
      }
   if (sum>K) continue;
   break;
}
printf("%d\n",i);
//for (;;);
}