#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
struct matrix
{
    int a[2][2];
    matrix()
    {
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
    }
    inline void init()
    {
        a[0][0]=a[0][1]=a[1][0]=a[1][1]=1e18;
    }
}sum[100001<<2];
inline matrix operator *(const matrix &x,const matrix &y)
{
    matrix res;
    res.init();
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                res.a[i][k]=min(res.a[i][k],x.a[i][j]+y.a[j][k]+1);
    return res;
}
int n,m,pos[100001][2][2];
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
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline int dis(int a1,int b1,int a2,int b2)
{
    return abs(a1-a2)+abs(b1-b2);
}
inline void push_up(int k)
{
    sum[k]=sum[ls(k)]*sum[rs(k)];
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                sum[k].a[i][j]=dis(pos[l][i][0],pos[l][i][1],pos[l+1][j][0]-!j,pos[l+1][j][1]-j);
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline matrix query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query(nl,nr,mid+1,r,rs(k));
    return query(nl,nr,l,mid,ls(k))*query(nl,nr,mid+1,r,rs(k));
}
signed main()
{
    n=read();
    for(int i=2;i<=n;++i)
    {
        pos[i][0][0]=read(),pos[i][0][1]=read(),pos[i][1][0]=read(),pos[i][1][1]=read();
        ++pos[i][0][0];
        ++pos[i][1][1];
    }
    if(n>2)
        build(1,2,n-1);
    m=read();
    while(m--)
    {
        int a1=read(),b1=read(),a2=read(),b2=read();
        int x=max(a1,b1),y=max(a2,b2);
        if(x==y)
            cout<<dis(a1,b1,a2,b2)<<'\n';
        else
        {
            if(x>y)
            {
                x^=y^=x^=y;
                a1^=a2^=a1^=a2;
                b1^=b2^=b1^=b2;
            }
            if(x+1==y)
                cout<<min(dis(a1,b1,pos[y][0][0]-1,pos[y][0][1])+dis(a2,b2,pos[y][0][0],pos[y][0][1])+1,dis(a1,b1,pos[y][1][0],pos[y][1][1]-1)+dis(a2,b2,pos[y][1][0],pos[y][1][1])+1)<<'\n';
            else
            {
                matrix w=query(x+1,y-1,2,n-1,1);
                int ans=1e18;
                for(int i=0;i<2;++i)
                    for(int j=0;j<2;++j)
                        ans=min(ans,dis(a1,b1,pos[x+1][i][0]-!i,pos[x+1][i][1]-i)+dis(a2,b2,pos[y][j][0],pos[y][j][1])+w.a[i][j]+2);
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}