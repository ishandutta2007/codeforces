#include<bits/stdc++.h>
#define ll long long
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
struct edge
{
	int next,to;
}e[1000005];
int cnt;
int h[1000005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct trie
{
	int to[26];
	int fail;
}tree[1000005];
int n,m;
char c[1000005];
int to[1000005];
int cst;
void insert(int id)
{
	int p=strlen(c);
	int last=0;
	for(int i=0;i<p;i++)
	{
//		cout<<last<<endl;
		if(!tree[last].to[c[i]-'a'])tree[last].to[c[i]-'a']=++cst;
		last=tree[last].to[c[i]-'a'];
	}
	to[id]=last;
//	cout<<last<<endl;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(tree[0].to[i])q.push(tree[0].to[i]);
	}
	while(!q.empty())
	{
		int x=q.front();
//		cout<<x<<" "<<tree[x].fail<<endl;
		add(tree[x].fail,x);
		q.pop();
//		cout<<q.size()<<endl;
		for(int i=0;i<26;i++)
		{
			if(!tree[x].to[i])
			{
				tree[x].to[i]=tree[tree[x].fail].to[i];
				continue;
			}
			tree[tree[x].to[i]].fail=tree[tree[x].fail].to[i];
			q.push(tree[x].to[i]);
		}
//		cout<<"wqqeqe"<<endl;
	}
//	cout<<"qweqeqe"<<endl;
}
int vis[1000005];
int lb(int x)
{
	return x&(-x);
}
int sum[1000005];
void ad(int x,int y)
{
	for(;x<=(cst+1);x+=lb(x))sum[x]+=y;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=sum[x];
	return ans;
}
void change(int x,int y,int v)
{
	ad(x,v);ad(y+1,-v);
}
int id[1000005];
int size[1000005];
int csp;
void dfs(int x)
{
	size[x]=1;
	id[x]=++csp;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		size[x]+=size[e[i].to];
	}
//	cout<<x<<" "<<id[x]<<" "<<size[x]<<endl;
}
void ask()
{
	int p=strlen(c);
	int last=0;
	int ans=0;
	for(int i=0;i<p;i++)
	{
//		cout<<last<<" "<<id[last]<<"Q"<<endl;
		last=tree[last].to[c[i]-'a'];
		ans+=ask(id[last]);
	}
	cout<<ans<<"\n";
}
signed main(){
//	freopen("a.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++)scanf("%s",c),insert(i);
	getfail();
	dfs(0);
	for(int i=1;i<=m;i++)
	{
//		cout<<to[i]<<endl;
		vis[i]=1;
		int x=i;
//		cout<<to[x]<<" "<<id[to[x]]<<" "<<
		change(id[to[x]],id[to[x]]+size[to[x]]-1,1);
	}
	while(n--)
	{
		char op;
		while((op=getchar())!='?'&&op!='+'&&op!='-');
		if(op=='?')
		{
			scanf("%s",c);
			ask();
		}
		if(op=='-')
		{
			int s=read();
			if(vis[s])vis[s]=0,change(id[to[s]],id[to[s]]+size[to[s]]-1,-1);
		}
		if(op=='+')
		{
			int s=read();
			if(!vis[s])vis[s]=1,change(id[to[s]],id[to[s]]+size[to[s]]-1,1);
		}
//		for(int i=1;i<=cst;i++)
//		{
//			cout<<ask(i)<<endl;
////			cout<<vis[i]<<endl;
//		}
	}
	return 0;
}