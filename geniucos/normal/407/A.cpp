#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int i,j,x[4000009],y[4000009],a,b,nr1,nr,x1,y11,x2,y2;
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&a);
scanf("%d",&b);
for(x1=0;x1<=a;x1++)
{
    y11=(int)sqrt((double)a*a-x1*x1);
    if(y11*y11+x1*x1==a*a)
    {
        x[++nr]=x1;
        y[nr]=y11;
        x[++nr]=x1;
        y[nr]=-y11;
        x[++nr]=-x1;
        y[nr]=y11;
        x[++nr]=-x1;
        y[nr]=-y11;
    }
}
nr1=nr;
for(x2=0;x2<=b;x2++)
{
    y2=(int)sqrt((double)b*b-x2*x2);
    if(x2*x2+y2*y2==b*b)
    {
        x[++nr]=x2;
        y[nr]=y2;
        x[++nr]=-x2;
        y[nr]=y2;
        x[++nr]=x2;
        y[nr]=-y2;
        x[++nr]=-x2;
        y[nr]=-y2;
    }
}
for(i=1;i<=nr1;i++)
    for(j=nr1+1;j<=nr;j++)
        if(x[i]!=x[j]&&y[i]!=y[j]&&det(0,0,x[i],y[i],x[j],y[j])!=0&&x[i]!=0&&y[i]!=0&&x[j]!=0&&y[j]!=0&&(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==a*a+b*b)
        {
            printf("YES\n");
            printf("0 0\n");
            printf("%d %d\n%d %d\n",x[i],y[i],x[j],y[j]);
            return 0;
        }
printf("NO\n");
return 0;
}