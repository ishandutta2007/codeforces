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
const int xx=2e5+5;
struct node{int link,size,end,to[26];}e[xx<<1];
int last,cst,tt;
void add(int x)
{
	int now=++cst,p=last;e[now].size=e[last].size+1;last=now,e[last].end=++tt;
	while(p&&!e[p].to[x])e[p].to[x]=now,p=e[p].link;
	if(!p)e[now].link=1;
	else 
	{
		int q=e[p].to[x];
		if(e[q].size==e[p].size+1)e[now].link=q;
		else 
		{
			int s=++cst;
			e[s].size=e[p].size+1;e[s].end=e[q].end;
			memcpy(e[s].to,e[q].to,sizeof(e[q].to));
			e[s].link=e[q].link;
			e[q].link=e[now].link=s;
			while(p&&e[p].to[x]==q)e[p].to[x]=s,p=e[p].link;
		}
	}
}
namespace S
{
	struct node{int l,r,sum;}e[xx*64];
	int cst;
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		int now=++cst;e[now].sum=e[x].sum+e[y].sum;
		e[now].l=merge(e[x].l,e[y].l);
		e[now].r=merge(e[x].r,e[y].r);
		return now;
	}
	void insert(int &k,int l,int r,int x)
	{
		cst++;e[cst]=e[k],k=++cst,e[k].sum++;
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)insert(e[k].l,l,mid,x);
		else insert(e[k].r,mid+1,r,x);
	}
	int ask(int k,int l,int r,int x,int y)
	{
		if(!k||x>y)return 0;
		if(x<=l&&r<=y)return e[k].sum;
		int mid=l+r>>1,ans=0;
		if(x<=mid)ans+=ask(e[k].l,l,mid,x,y);
		if(mid<y)ans+=ask(e[k].r,mid+1,r,x,y);
		return ans;
	}
}using S::ask;
using S::insert;
using S::merge;
int root[xx<<1],n,id[xx<<1],T[xx<<1];
char s[xx];
int f[xx<<1][21],g[xx<<1];
signed main(){
	last=cst=1;
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)add(s[i]-'a');
	for(int i=1;i<=cst;i++)T[e[i].size]++;
	for(int i=1;i<=n;i++)T[i]+=T[i-1];
	for(int i=1;i<=cst;i++)id[T[e[i].size]--]=i;
	last=1;
	for(int i=1;i<=n;i++)
	{
		last=e[last].to[s[i]-'a'];
		insert(root[last],1,n,i);
	}
	for(int i=cst;i>=1;i--)
	{
		int x=id[i];
		root[e[x].link]=merge(root[e[x].link],root[x]);
	}
	for(int i=1;i<=cst;i++)f[i][0]=e[i].link;
	for(int j=1;j<=20;j++)for(int i=1;i<=cst;i++)f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=cst;i++)
	{
		int x=id[i];
		if(x==1)continue;
		int now=x;
		g[x]=max(g[x],g[e[x].link]);
		for(int j=20;j>=0;j--)
		{
			if(!f[now][j])continue;
			int t=f[now][j];
			if(g[t]==g[x])now=t;
		}
		if(!ask(root[now],1,n,e[x].end-e[x].size+e[now].size,e[x].end-1))now=0;
		g[x]=max(g[x],g[now]+1);
		for(int j=0;j<26;j++)if(e[x].to[j])g[e[x].to[j]]=max(g[e[x].to[j]],g[x]);
	}
	cout<<g[last]<<'\n';
	return 0;
}
//accdsaccdw
//abbabbabbab