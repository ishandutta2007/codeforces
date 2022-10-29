#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
struct Node{int x,y;}a[100001];
int ans=(int)1e9;
int front[200001],back[200001],q[200001],same[200001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),q[++q[0]]=a[i].x,q[++q[0]]=a[i].y;
  sort(q+1,q+q[0]+1);
  q[0]=unique(q+1,q+q[0]+1)-(q+1);
  for (i=1;i<=n;i++)
 { int X=lower_bound(q+1,q+q[0]+1,a[i].x)-q;
   int Y=lower_bound(q+1,q+q[0]+1,a[i].y)-q;
   if (X==Y)
   {   front[X]++; same[X]++; }
   else  { 
           front[X]++; back[Y]++;
}
}
for (i=1;i<=q[0];i++)
 if (front[i]+back[i]>=(n+1)/2)
 {   ans=min(ans,max(0,(n+1)/2-front[i]));
}
if (ans==(int)1e9) printf("-1\n");else 
printf("%d\n",ans);
}