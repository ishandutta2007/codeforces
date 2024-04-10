#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n; 
struct node
{
	int next,to;
}e[200005];
int cnt;
int h[100005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int size[100005];
int maxx=n;
vector<int>v;
void dfs(int x,int y)
{
	size[x]=1;
	int minn=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to!=y)
		{
			dfs(e[i].to,x);
			size[x]+=size[e[i].to];
			minn=max(minn,size[e[i].to]);
		}
	}
	minn=max(minn,n-size[x]);
	if(minn<maxx)
	{
		maxx=minn;
		v.clear();
	}
	if(minn==maxx)
	{
		v.push_back(x);
	}
}
void DFS(int x,int y)
{
	int w=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(e[i].to==v[1])continue;
		DFS(e[i].to,x);
		w=0;
		break;
	}
	if(w)
	{
		printf("%d %d\n",x,y);
		printf("%d %d\n",x,v[1]);
	}
}
int main(){
	int T;
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=cnt;i++)
		{
			e[cnt].to=e[cnt].next=0;
		}
		for(int i=1;i<=n;i++)
		{
			h[i]=0;
			size[i]=0;
		}
		maxx=n;
		v.clear();
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a,b;
			a=read();
			b=read();
			add(a,b);
			add(b,a);
		}
		dfs(1,0);
		if(v.size()==1)
		{
			for(int i=h[1];i;i=e[i].next)
			{
				printf("%d %d\n",1,e[i].to);
				printf("%d %d\n",1,e[i].to);
				break;
			}
			continue;
		}
		else 
		{
			DFS(v[0],0);
			continue;
		}
	}
	return 0;
}