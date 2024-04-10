#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int cnt=0,n,m;
struct edge{
    int to,next;
}e[300005];
int head[300005];
ll num,sum;
bool mark[300005];

inline void ins(int u,int v)
{
    e[++cnt].next=head[u];head[u]=cnt;
    e[cnt].to=v;
}

void dfs(int x)
{
    mark[x]=1;num++;
    for(int i=head[x];i;i=e[i].next,sum++)if(!mark[e[i].to])
        dfs(e[i].to);
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {int  a=read();int  b=read();ins(a,b);ins(b,a);}
    for(int i=1;i<=n;i++)if(!mark[i])
    {num=sum=0;dfs(i);
        if(num>2&&sum!=(num-1)*num)return 0*puts("NO");
        //   if(num==2&&sum!=2)return 0*puts("NO");
    }
    puts("YES");
    return 0;
}