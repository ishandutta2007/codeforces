#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
struct Node{int x;double y;}a[5001];
inline bool cmp(Node a,Node b) { return a.y<b.y;}
int f[5001];
int main()
{scanf("%d%d",&n,&m);
 for (i=1;i<=n;i++) scanf("%d%lf",&a[i].x,&a[i].y);
 sort(a+1,a+n+1,cmp);
 for (i=1;i<=n;i++)
 {  f[i]=1;
    for (j=1;j<i;j++)
     if (a[i].x>=a[j].x)f[i]=max(f[i],f[j]+1);
     ans=max(ans,f[i]);
 }
 printf("%d\n",n-ans);
}