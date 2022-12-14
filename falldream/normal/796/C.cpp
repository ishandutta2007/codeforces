#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<cmath>
#define ll long long
#define N 524288
#define MN 300005
#define INF 2000000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

struct edge{int to,next;}e[MN*5];
int cnt=0,n,a[MN+5],head[MN+5],ans=INF;
int T[MN*10];

void renew (int x,int ad)
{
    T[x+=N]=ad;
    for(x>>=1;x;x>>=1)
        T[x]=max(T[x<<1],T[x<<1|1]);
}

int query(int l,int r)
{
    int sum=-INF;
    for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
    {
        if(~l&1) sum=max(sum,T[l+1]);
        if( r&1) sum=max(sum,T[r-1]);
    }
    return sum;
}

void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}

int main()
{
    n=read();
    memset(T,128,sizeof(T));
    for(int i=1;i<=n;i++)
        a[i]=read(),renew(i,a[i]+2);
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        ins(x,y);
    }
    for(int x=1;x<=n;x++)
    {
        renew(x,a[x]);
        for(int i=head[x];i;i=e[i].next)
            renew(e[i].to,a[e[i].to]+1);
        ans=min(ans,query(1,n));
        renew(x,a[x]+2);
        for(int i=head[x];i;i=e[i].next)
            renew(e[i].to,a[e[i].to]+2);
    }
    printf("%d\n",ans);
    return 0;
}