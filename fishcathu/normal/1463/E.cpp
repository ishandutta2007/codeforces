#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int head[N],nex[N],_nex[N],ans[N],fa[N],in[N],_fa[N];
queue<int>q;
bool vis[N];
void add(int u,int v)
{
	nex[v]=head[u];
	head[u]=v;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n=read(),m=read(),cnt=-1;
	for(int i=1;i<=n;++i)
	{
		int u=read();
		add(u,i);
		_fa[i]=u;
		fa[i]=i;
	}
	memset(_nex,-1,sizeof _nex);
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		if(~_nex[u]||fa[v]!=v||find(u)==v)
		{
			puts("0");
			return 0;
		}
		fa[v]=u;
		_nex[u]=v;
	}
	for(int i=1;i<=n;++i)if(fa[i]==i)
	{
		for(int j=i;~j;j=_nex[j])
		{
			vis[j]=1;
			if(find(_fa[j])!=i)++in[i];
			else if(!vis[_fa[j]])
			{
				puts("0");
				return 0;
			}
		}
	}
	q.push(0);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=t;~i;i=_nex[i])
		{
			ans[++cnt]=i;
			for(int j=head[i];j;j=nex[j])
			{
				int v=find(j);
				--in[v];
				if(!in[v])q.push(v);
			}
		}
	}
	if(cnt!=n)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}