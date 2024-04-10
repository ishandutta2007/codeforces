#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int x,y,bh;}a[100001];
int i,j,m,n,p,k;
inline bool cmp(Node a,Node b)
{  if (a.x!=b.x) return a.x<b.x; else return a.y<b.y; }
int main()
 {scanf("%d",&n);
   for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].bh=i;
   sort(a+1,a+n+1,cmp);
   for (i=2;i<=n;i++)
    if (a[i].x!=a[i-1].x) break;
    i--;
   for (j=1;j<=n;j++)
    if (a[j].x<a[i].x||a[j].y>a[i].y) { printf("-1\n"); return 0;}
 printf("%d\n",a[i].bh);
}