#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long l,r,mid,d;
int i,j,m,n,p,k,x;
struct Node{int x,y;}A[101];
long long cost[101],vis[101],Que[100001],a[101];
int dis(int a,int b) { return x=(abs(A[a].x-A[b].x)+abs(A[a].y-A[b].y))*d; } 
int check(long long x)
{ memset(cost,-1,sizeof(cost)); vis[1]=1; cost[1]=x;
  int l=1,r=1,i; Que[1]=1;
  for (;l<=r;l++)
  {   int p=Que[l];
    for (i=1;i<=n;i++)
    if (cost[p]-dis(p,i)>=0&&i!=p&&cost[p]-dis(p,i)+a[i]>cost[i])
	{   cost[i]=cost[p]-dis(p,i)+a[i];
	    if (!vis[i]) {vis[i]=1; Que[++r]=i; }
}
vis[p]=0;
}
return (cost[n]!=-1);
}
int main()
{ scanf("%d%I64d",&n,&d);
 for (i=2;i<n;i++) scanf("%d",&a[i]);
 for (i=1;i<=n;i++) scanf("%d%d",&A[i].x,&A[i].y);
l=0; r=(long long)(1ll<<60);
for (;(l+r)>>1ll!=mid;)
{ mid=(l+r)>>1;
  if (check(mid)) r=mid; else l=mid; }
printf("%I64d\n",r);
}