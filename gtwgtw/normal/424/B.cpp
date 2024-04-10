#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


struct Node
{
    int x,y,k;
}a[1005];
int n,peo;
int g[105];


inline int cmp(const Node &xx,const Node &yy)
{
    int X=abs(xx.x),Y=abs(xx.y),x=abs(yy.x),y=abs(yy.y);
    return X*X+Y*Y<x*x+y*y;
}


int main()
{
    scanf("%d%d",&n,&peo);
    int tmp=peo;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].k);
        tmp+=a[i].k;
    }
    if(tmp<1000000)
    {
        printf("-1\n");
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        peo+=a[i].k;
        if(peo>=1000000)
        {
            double dis=sqrt(abs(a[i].x)*abs(a[i].x)+abs(a[i].y)*abs(a[i].y));
            printf("%.7lf\n",dis);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}