#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sum[1000001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=n;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline void del(int x)
{
    if(query(n)<x)
        return;
    int pos=0,val=0;
    for(int i=20;~i;--i)
    {
        if((pos|(1<<i))>n)
            continue;
        if(val+sum[pos|(1<<i)]<x)
        {
            pos|=1<<i;
            val+=sum[pos];
        }
    }
    update(pos+1,-1);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        update(read(),1);
    while(m--)
    {
        int k=read();
        if(k<0)
            del(-k);
        else
            update(k,1);
    }
    for(int i=1;i<=n;++i)
        if(query(i))
        {
            cout<<i<<'\n';
            return 0;
        }
    cout<<"0\n";
    return 0;
}