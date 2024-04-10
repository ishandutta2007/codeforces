#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sum[2][100001],cnt[2][100001];
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
inline void update(int x,int tag,int val)
{
    for(;x<=n;x+=lowbit(x))
        sum[tag][x]+=val;
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[tag][x];
    return res;
}
int main()
{
    n=read(),m=read();
    while(m--)
    {
        int opt=read();
        if(opt==1)
        {
            int x=read(),y=read();
            if(!cnt[0][x]++)
                update(x,0,1);
            if(!cnt[1][y]++)
                update(y,1,1);
        }
        if(opt==2)
        {
            int x=read(),y=read();
            if(!--cnt[0][x])
                update(x,0,-1);
            if(!--cnt[1][y])
                update(y,1,-1);
        }
        if(opt==3)
        {
            int l1=read(),r1=read(),l2=read(),r2=read();
            cout<<(query(l2,0)-query(l1-1,0)==l2-l1+1||query(r2,1)-query(r1-1,1)==r2-r1+1? "YES":"NO")<<'\n';
        }
    }
    return 0;
}