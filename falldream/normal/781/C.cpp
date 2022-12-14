#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int ans[400005];
bool b[400005];
struct edge{
	int to,next;
}e[800005];
int head[400005];
int n,m,k,cnt=0,top=0,q[500005];

void ins(int f,int t)
{
	e[++cnt].next=head[f];head[f]=cnt;
	e[cnt].to=t;
}

void dfs(int x,int fa)
{
	b[x]=1;q[++top]=x;
	for(int i=head[x];i;i=e[i].next)
	if(!b[e[i].to])
	{
		dfs(e[i].to,x);
		q[++top]=x;
	}
}

int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++)
    {int u=read(),v=read();ins(u,v);ins(v,u);}
    dfs(1,0);
    int l=(top+k-1)/k;
    int i=1;
    for(int pre=0;i<=k&&pre<top;i++,pre+=l)
    {
		int l2=min(l,top-pre);
		printf("%d ",l2);
		for(int j=1;j<=l2;j++)
			printf("%d ",q[pre+j]);
		puts("");
	}
	while(i<=k){i++;printf("1 1\n");}
    return 0;
}