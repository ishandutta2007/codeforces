#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int n,m,a[2001][2001],sum[4001][4001];
pair<int,int> pos[2001*2001];
bool sg[2001][2001];
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
inline void update(int x,int y)
{
    for(int i=x;i<=n+n;i+=lowbit(i))
        for(int j=y;j<=n+n;j+=lowbit(j))
            ++sum[i][j];
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
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            pos[a[i][j]=read()]={i,j};
    for(int i=n*n;i>=1;--i)
    {
        int x=pos[i].first+pos[i].second,y=pos[i].first-pos[i].second+n;
        int l1=max(x-m,1),l2=min(x+m,n+n),r1=max(y-m,1),r2=min(y+m,n+n);
        if((sg[pos[i].first][pos[i].second]=!(query(n+n,n+n)-(query(l2,r2)-query(l2,r1-1)-query(l1-1,r2)+query(l1-1,r1-1)))))
            update(x,y);
    }
    for(int i=1;i<=n;++i,cout<<'\n')
        for(int j=1;j<=n;++j)
            cout<<(sg[i][j]? 'M':'G');
    return 0;
}