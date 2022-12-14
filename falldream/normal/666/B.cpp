#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 3000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int head[MN+5],cnt=0,n,m,d[MN+5][MN+5],q[MN+5],top,ans,a[4];
int mx[3][MN+5],from[3][MN+5],Mx[3][MN+5],From[3][MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}

void Add2(int x,int y,int len)
{
    if(len>Mx[0][x])
    {
        From[2][x]=From[1][x];Mx[2][x]=Mx[1][x];
        From[1][x]=From[0][x];Mx[1][x]=Mx[0][x];
        From[0][x]=y;Mx[0][x]=len;
    }
    else if(len>Mx[1][x])
    {
        From[2][x]=From[1][x];Mx[2][x]=Mx[1][x];
        From[1][x]=y;Mx[1][x]=len;
    }
    else if(len>Mx[2][x]){From[2][x]=y;Mx[2][x]=len;}
}


void Add1(int x,int y,int len)
{
    if(len>mx[0][x])
    {
        from[2][x]=from[1][x];mx[2][x]=mx[1][x];
        from[1][x]=from[0][x];mx[1][x]=mx[0][x];
        from[0][x]=y;mx[0][x]=len;
    }
    else if(len>mx[1][x])
    {
        from[2][x]=from[1][x];mx[2][x]=mx[1][x];
        from[1][x]=y;mx[1][x]=len;
    }
    else if(len>mx[2][x]){from[2][x]=y;mx[2][x]=len;}
}
inline void R(int A,int B,int C,int D,int res){if(res>ans) ans=res,a[0]=A,a[1]=B,a[2]=C,a[3]=D;}
int main()
{
    n=read();m=read();
    memset(d,63,sizeof(d));
    for(int i=1,j;i<=m;++i) j=read(),ins(j,read());
    for(int i=1;i<=n;++i)
    {
        d[i][q[top=1]=i]=0;
        for(int j=1;j<=top;++j)
        {
            for(int k=head[q[j]];k;k=e[k].next)
                if(d[i][q[j]]+1<d[i][e[k].to]) d[i][q[++top]=e[k].to]=d[i][q[j]]+1;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) if(i!=j&&d[i][j]<1e9)
            Add2(j,i,d[i][j]),Add1(i,j,d[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) if(i!=j&&d[i][j]<1e9)
            for(int k=0;k<3;++k) if(From[k][i]!=j&&From[k][i])
                for(int l=0;l<3;++l) if(from[l][j]!=i&&from[l][j]!=From[k][i]&&from[l][j])
                    R(From[k][i],i,j,from[l][j],Mx[k][i]+d[i][j]+mx[l][j]);
    printf("%d %d %d %d",a[0],a[1],a[2],a[3]);
    return 0;
}