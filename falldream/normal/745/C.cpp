#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,m,v,size;
bool b[10005];
struct edge{
   int to,next;
}e[1000005];
int head[10005];
int cnt=0;
int maxn=0;
int q[10005];

inline void ins(int f,int t)
{
     e[++cnt].next=head[f];
     head[f]=cnt;
     e[cnt].to=t;
}

void dfs(int x)
{
    size++;b[x]=1;
    for(int i=head[x];i>0;i=e[i].next)
    {
   	int t=e[i].to;
	if(b[t]) continue;
	dfs(t);
    }
}

int main()
{
    n=read();m=read();v=read();
    for(int i=1;i<=v;i++)
    {
   	q[i]=read();        
    }
    for(int i=1;i<=m;i++)
    {
	int x=read(),y=read();
	ins(x,y);
	ins(y,x);
    }
    int ans=0,tot=n;
    for(int i=1;i<=v;i++)
    {
        size=0;
	dfs(q[i]);tot-=size;
	ans+=(size*(size-1));
	maxn=max(maxn,size);
    }
    ans-=(maxn*(maxn-1));
    maxn+=tot;
    ans+=(maxn*(maxn-1));
    cout<<ans/2-m;
    return 0;
}