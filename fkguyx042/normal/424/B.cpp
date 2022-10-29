#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct node{int x;int y;int num;}a[1001];
int i,j,m,n,p,k,s,sum;
inline int sqr(int num)
{ return num*num;}
double ans;
int main()
 {scanf("%d%d",&n,&s);
   for (i=1;i<=n;i++)
    { scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].num);
        sum+=a[i].num;
}
ans=1e9;
if (sum+s<1000000) {printf("-1\n"); return 0;}
for (i=1;i<=n;i++)
  { sum=0;
     for (j=1;j<=n;j++)
      if ((double)(sqr(a[j].x)+sqr(a[j].y))<=(double)(sqr(a[i].x)+sqr(a[i].y)))
        sum+=a[j].num;
     if (sum+s>=1000000) ans=min(ans,(double)sqrt(sqr(a[i].x)+sqr(a[i].y)));
}
printf("%.7lf\n",ans);
return 0;
}