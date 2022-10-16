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
const int xx=1e5+5;
struct node
{
	int next,to;
}e[xx<<1];
int h[xx];
int cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int size[xx];
int son[xx];
int t[xx];
int s[xx];
int val[xx];
void dfs(int x,int y)
{
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to;
	}
}
void add(int x,int y,int op)
{
	if(op==-1)s[t[val[x]]]--;
	t[val[x]]+=op;
	if(op==1)s[t[val[x]]]++;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)add(e[i].to,x,op);
}
vector<int>k[xx];
vector<int>id[xx];
int n,m;
int ans[xx];
void dfss(int x,int y)
{
//	cout<<x<<endl;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||e[i].to==son[x])continue;
		dfss(e[i].to,x);
		add(e[i].to,x,-1);
	}
	if(son[x])dfss(son[x],x);
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y&&e[i].to!=son[x])add(e[i].to,x,1);
	t[val[x]]++;
	s[t[val[x]]]++;
	for(int i=0;i<k[x].size();i++)ans[id[x][i]]=s[k[x][i]];
//	cout<<x<<"\n";
//	for(int i=1;i<=n;i++)cout<<t[i]<<" \n"[i==n];
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=m;i++)
	{
		int x,u;
		x=read();
		u=read();
		k[x].push_back(u);
		id[x].push_back(i);
	}
	dfs(1,0);
	dfss(1,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}