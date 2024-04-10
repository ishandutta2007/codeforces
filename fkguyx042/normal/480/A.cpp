#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Last;
struct Node{int x,y;}a[10001];
inline bool cmp(Node a,Node b) { if (a.x!=b.x) return a.x<b.x; return a.y<b.y;}
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
 sort(a+1,a+n+1,cmp);
 Last=0;
 for (i=1;i<=n;i++)
{  if(Last<=a[i].y) Last=a[i].y;
   else Last=a[i].x;
}
printf("%d\n",Last);
}