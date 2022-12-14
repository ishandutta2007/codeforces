#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#define MN 1000
#define pa pair<double,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
double f[MN+5][MN+5],p[MN+5],F[MN+5];
int n,b[MN+5];

int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f[i][j]=(double)read()/100;
    for(int i=1;i<n;++i) p[i]=1;
    for(int i=1;i<=n;++i)
    {
        double mn=1e18;int k=0;
        for(int j=1;j<=n;++j)
            if(!b[j]&&p[j]<1&&(p[j]+F[j])/(1-p[j])<mn)
                mn=(p[j]+F[j])/(1-p[j]),k=j;
        b[k]=1;F[k]=(F[k]+p[k])/(1-p[k]);
        for(int j=1;j<=n;++j) if(!b[j])
            F[j]+=p[j]*f[j][k]*(F[k]+1),p[j]=p[j]*(1-f[j][k]);
    }
    printf("%.10lf\n",F[1]);
    return 0;
}