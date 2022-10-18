#include<iostream>
#include<cstdio>
using namespace std;
struct element
{
    int opt,x,y,len;
}q[100001];
int n,m,ans[100001],sum[10001][5001];
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int y,int val)
{
    for(int i=x;i<=n+n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            sum[i][j]+=val;
}
inline int query(int x,int y)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=sum[i][j];
    return res;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int opt=read();
        if(opt==1)
            q[i].opt=read(),q[i].x=read(),q[i].y=read(),q[i].len=read();
        else
            q[i].opt=5,q[i].x=read(),q[i].y=read();
        if(q[i].opt==1)
        {
            update(q[i].x,q[i].y,1);
            update(q[i].x,q[i].y+q[i].len+1,-1);
        }
        if(q[i].opt==2)
        {
            update(q[i].x,q[i].y-q[i].len,1);
            update(q[i].x,q[i].y+1,-1);
        }
        if(q[i].opt==3)
        {
            update(q[i].x+1,q[i].y+q[i].len+1,1);
            update(q[i].x+1,q[i].y,-1);
        }
        if(q[i].opt==4)
        {
            update(q[i].x+1,q[i].y+1,1);
            update(q[i].x+1,q[i].y-q[i].len,-1);
        }
        if(q[i].opt==5)
            ans[i]+=query(q[i].x,q[i].y);
    }
    for(int i=0;i<=n+n;++i)
        for(int j=0;j<=n;++j)
            sum[i][j]=0;
    for(int i=1;i<=m;++i)
    {
        if(q[i].opt==1)
        {
            update(q[i].x+q[i].y+q[i].len+1,n-q[i].y+2,1);
            update(q[i].x+q[i].y+q[i].len+1,n-q[i].y-q[i].len+1,-1);
        }
        if(q[i].opt==4)
        {
            update(q[i].x+q[i].y-q[i].len,n-q[i].y+1,1);
            update(q[i].x+q[i].y-q[i].len,n-q[i].y+q[i].len+2,-1);
        }
        if(q[i].opt==5)
            ans[i]+=query(q[i].x+q[i].y,n-q[i].y+1);
    }
    for(int i=0;i<=n+n;++i)
        for(int j=0;j<=n;++j)
            sum[i][j]=0;
    for(int i=1;i<=m;++i)
    {
        if(q[i].opt==2)
        {
            update(q[i].x-q[i].y+q[i].len+n+2,q[i].y+1,1);
            update(q[i].x-q[i].y+q[i].len+n+2,q[i].y-q[i].len,-1);
        }
        if(q[i].opt==3)
        {
            update(q[i].x-q[i].y-q[i].len+n+1,q[i].y,1);
            update(q[i].x-q[i].y-q[i].len+n+1,q[i].y+q[i].len+1,-1);
        }
        if(q[i].opt==5)
            ans[i]+=query(q[i].x-q[i].y+n+1,q[i].y);
    }
    for(int i=1;i<=m;++i)
        if(q[i].opt==5)
            cout<<ans[i]<<'\n';
    return 0;
}