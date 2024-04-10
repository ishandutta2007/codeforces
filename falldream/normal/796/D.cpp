#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<cmath>
#define ll long long
#define MN 300005
#define INF 200000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

struct edge{int to,next;}e[MN*5];
int cnt=1,n,k,mx,head[MN+5],d[MN+5],num,q[MN+5],sum=0,fa[MN+5],ans[MN+5];

void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}

int main()
{
    n=read();k=read();mx=read();
    if(!mx){
       printf("%d\n",n-1);
        for(int i=1;i<n;i++) printf("%d ",i);
        return 0;
    }
    memset(d,42,sizeof(d));
    for(int i=1;i<=k;i++)
    {
        int x=read();if(d[x]<INF)continue;
        q[++num]=x;d[x]=0;
    }
    for(int i=1;i<n;i++) ins(read(),read());
    for(int i=1;i<=num;i++)
        for(int j=head[q[i]];j;j=e[j].next)
        if(e[j].to!=fa[q[i]])
        {
            if(d[e[j].to]<INF) sum+=ans[j>>1]^1,ans[j>>1]=1;
            else d[q[++num]=e[j].to]=d[q[i]]+1,fa[e[j].to]=q[i];
        }
    printf("%d\n",sum);
    for(int i=1;i<n;i++)
        if(ans[i]) printf("%d ",i);
    return 0;
}