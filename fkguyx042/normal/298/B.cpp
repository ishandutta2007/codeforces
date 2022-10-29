#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,sx,sy,ex,ey;
int x,y,f1,f2;
char c;
int main()
{ scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey);
if (sx>ex) f1=1;
if (sy>ey) f2=1;
int X=abs(sx-ex);
int Y=abs(sy-ey); c=getchar();
for (i=1;i<=n;i++)
{ c=getchar();
  if (f1==0&&c=='E') x++;
  if (f1==1&&c=='W') x++;
  if (f2==0&&c=='N') y++;
  if (f2==1&&c=='S') y++;
  if (x>=X&&y>=Y) { printf("%d\n",i); return 0;}
}
printf("-1\n");
}