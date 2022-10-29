#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Node{int x,y;double jd;}a[100001];
int i,j,m,n,p,k;
double ans;
inline bool cmp(Node a,Node b) { return a.jd<b.jd;}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].jd=atan2(a[i].y,a[i].x)*180.0/acos(-1.0);
  sort(a+1,a+n+1,cmp); 
  a[n+1].jd=a[1].jd+360;
  ans=360.0;
  for (i=1;i<=n;i++)
    ans=min(ans,360-a[i+1].jd+a[i].jd);
    printf("%.10lf\n",ans);
}