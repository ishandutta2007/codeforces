#include<cstdio>
#include<algorithm>
using namespace std;
int a[300001],ans[300001],Now,n,i;
struct Node{int x,y;}s[300001];
inline bool cmp(Node a,Node b) { return a.x<b.x;}
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]),s[i].x=a[i],s[i].y=i;
 sort(s+1,s+n+1,cmp);
 for (i=1;i<=n;i++)
  if (Now>=s[i].x)
  ans[s[i].y]=++Now;
  else ans[s[i].y]=s[i].x,Now=s[i].x;
  for (i=1;i<=n;i++) printf("%d ",ans[i]);
}