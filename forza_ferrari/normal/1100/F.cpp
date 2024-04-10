#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500001],p[500001][21],pos[500001][21];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void insert(int x,int y,int k)
{
    for(int i=20;~i;--i)
    {
        if(!(x&(1<<i)))
            continue;
        if(!p[k][i])
        {
            p[k][i]=x;
            pos[k][i]=y;
            return;
        }
        if(pos[k][i]<y)
        {
            x^=p[k][i]^=x^=p[k][i];
            y^=pos[k][i]^=y^=pos[k][i];
        }
        x^=p[k][i];
    }
}
inline int query(int l,int r)
{
    int res=0;
    for(int i=20;~i;--i)
        if(!(res&(1<<i))&&pos[r][i]>=l)
            res^=p[r][i];
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        for(int j=0;j<=20;++j)
        {
            p[i][j]=p[i-1][j];
            pos[i][j]=pos[i-1][j];
        }
        insert(a[i],i,i);
    }
    m=read();
    while(m--)
    {
        int l=read(),r=read();
        printf("%d\n",query(l,r));
    }
    return 0;
}