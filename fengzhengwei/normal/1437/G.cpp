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
int n,m;
struct node
{
	int next,to;
}e[600005];
int cnt;
int h[300005];
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
}tree[300005];
char c[1000005];
int cst=1;
int to[300005];
int vis[300005];
multiset<int>s[300005];
void insert(int x)
{
	int p=strlen(c+1);
	int last=1;//1 
	for(int i=1;i<=p;i++)
	{
		if(!tree[last].to[c[i]-'a'])tree[last].to[c[i]-'a']=++cst;
		last=tree[last].to[c[i]-'a'];
	}
	to[x]=last;
//	if(x==5)cout<<last<<endl;
	vis[last]=1;
	s[last].insert(0);
//	cout<<last<<endl;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(tree[1].to[i])q.push(tree[1].to[i]),tree[tree[1].to[i]].fail=1;
		else tree[1].to[i]=1;
	}
	tree[1].fail=1;
	while(!q.empty())
	{
		int x=q.front();
		add(tree[x].fail,x);
		q.pop();
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
	}
}
const int ss=300005;
int dep[ss],f[ss],top[ss],id[ss],csp,son[ss],size[ss],td[ss];
void dfs1(int x,int y)
{
	f[x]=y;
	dep[x]=dep[y]+1;
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to;
	}
}
void dfs2(int x,int t)
{
//	cout<<x<<"\n";
	top[x]=t;
	id[x]=++csp;
	td[csp]=x;
	if(!son[x])return;
	dfs2(son[x],t);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to!=f[x]&&e[i].to!=son[x])dfs2(e[i].to,e[i].to);
	}
}
int maxx[1200005];
int val[ss];
void build(int k,int l,int r)
{
	if(l==r)
	{
		maxx[k]=*(--s[td[l]].end());
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
void change(int k,int l,int r,int x,int y,int z)//xlastyyzl=x 
{
	if(l==r)
	{
		s[td[l]].erase(s[td[l]].find(val[y]));
		val[y]=z;
		s[td[l]].insert(val[y]);
		maxx[k]=*(--s[td[l]].end());
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y,z);
	else change(k<<1|1,mid+1,r,x,y,z);
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y)
{
	if(r<x||y<l)return -1;
	if(x<=l&&r<=y)
	{
		return maxx[k];
	}
	int mid=l+r>>1;
	return max(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
int ask(int x)
{
	int ans=-1;
	while(top[x]!=1)
	{
//		cout<<top[x]<<" "<<x<<endl;
		ans=max(ans,ask(1,1,cst,id[top[x]],id[x]));
		x=f[top[x]];
	}
	ans=max(ans,ask(1,1,cst,id[top[x]],id[x]));
//	cout<<ans<<" "<<id[top[x]]<<" "<<id[x]<<endl;
	return ans;
}
int viw[10000005];
int ooo;
void ask()
{
	int ans=-1;
	int p=strlen(c+1);
	int last=1;
	int nows=++ooo;
	for(int i=1;i<=p;i++)
	{
		last=tree[last].to[c[i]-'a'];
		int o=last;
//		while(o!=1)
//		{
//			cout<<o<<endl;
//			o=f[o];
//		}
//		cout<<last<<endl;
		if(viw[last]!=ooo)ans=max(ans,ask(last)),viw[last]=ooo;
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
//	freopen("a.in","r",stdin);
	memset(maxx,-1,sizeof(maxx));
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c+1);
		insert(i);
	}
	for(int i=1;i<=cst;i++)
	{
		if(!s[i].size())s[i].insert(-1);
	}
	getfail();
	dfs1(1,0);
	dfs2(1,1);
//	cout<<"qwqeqe"<<endl;
	build(1,1,cst);
	while(m--)
	{
//		cout<<m<<endl;
		int op=read();
		if(op==1)
		{
			int x,y;
			x=read();
			y=read();
			change(1,1,cst,id[to[x]],x,y);
		}
		else 
		{
			scanf("%s",c+1);
			ask();
		}
	}
	return 0;
}