#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 50
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
double f[MN+5][MN*100+5],mid;
int n,R,p[MN+5],a[MN+5],b[MN+5];
inline double cal(int x,int y){return y>=0?f[x][y]:mid;}
int main()
{
    n=read();R=read();
    for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),p[i]=read();
    double l=0,r=1e9;
    for(int i=1;i<=100;++i)
    {
        mid=(l+r)/2.0;
        for(int i=n;i;--i)
            for(int j=0;j<=R;++j)
                f[i][j]=min(mid,(double)p[i]/100*(cal(i+1,j-a[i])+a[i])+
                                (double)(100-p[i])/100*(cal(i+1,j-b[i])+b[i]));
      //  printf("%.5lf %.5lf\n",mid,f[1][R]);
        if(f[1][R]<mid) r=mid;
        else l=mid;
    }
    printf("%.10lf",(l+r)/2);
    return 0;
}