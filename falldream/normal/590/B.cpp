#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 500000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int v,t,xx,X,yy,Y,vx,vy,wx,wy;
int main()
{
    xx=read();yy=read();X=read();Y=read();
    v=read();t=read();
    vx=read();vy=read();wx=read();wy=read();
    double l=0,r=t,mid,res=-1;
    for(int i=1;i<=100;++i)
    {
        mid=(l+r)/2.0;
        double nx=X-vx*mid,ny=Y-vy*mid;
        if(mid*v>=sqrt((nx-xx)*(nx-xx)+(ny-yy)*(ny-yy))) res=mid,r=mid;
        else l=mid;
    }
    if(res!=-1) return 0*printf("%.10lf",res);
    l=t,r=1e9;
    for(int i=1;i<=100;++i)
    {
        mid=(l+r)/2.0;
        double nx=X-1LL*vx*t-wx*(mid-t),ny=Y-1LL*vy*t-wy*(mid-t);
        if(mid*v>=sqrt((nx-xx)*(nx-xx)+(ny-yy)*(ny-yy))) res=mid,r=mid;
        else l=mid;
    }
    printf("%.10lf",res);
    return 0;
}