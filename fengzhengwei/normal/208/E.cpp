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
int n,m;
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
int stk[xx];
int top;
vector<int>ka[xx];//kth_ancester 
vector<int>ida[xx];//kth_ancester's id 
vector<int>ks[xx];//kth_son
vector<int>ids[xx];//kth_son's id
int ans[xx];
int d[xx];
int md[xx];
int son[xx];
void dfs(int x,int y)
{
	d[x]=d[y]+1;
	md[x]=d[x];
	int maxx=-1;
	stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		md[x]=max(md[x],md[e[i].to]);
		if(md[e[i].to]>maxx)maxx=md[e[i].to],son[x]=e[i].to;
	}
	for(int i=0;i<ka[x].size();i++)
	{
		if(d[x]<=ka[x][i])continue;
		int s=stk[top-ka[x][i]];
//		cout<<s<<" qwq "<<ida[x][i]<<"\n";
		ks[s].push_back(ka[x][i]);
		ids[s].push_back(ida[x][i]);
	}
	top--;
}
int g[xx<<1];
int *f[xx];
int *id;
void dfss(int x,int y)
{
//	if(x==3)cout<<x<<" ssss"<<f[3][0]<<endl;
	if(son[x])
	{
		f[son[x]]=f[x]+1;
		dfss(son[x],x);
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||e[i].to==son[x])continue;
		f[e[i].to]=id;
		id+=(md[e[i].to]-d[e[i].to]+1);
		dfss(e[i].to,x);
		for(int j=0;j<=md[e[i].to]-d[e[i].to];j++)f[x][j+1]+=f[e[i].to][j];
	}
	f[x][0]++;
//	cout<<"qweqeq";
//	cout<<x<<"\n";
//	for(int i=0;i<=md[x]-d[x]+1;i++)cout<<f[x][i]<<" \n"[i==(md[x]-d[x]+1)];
//	puts("");
	for(int i=0;i<ks[x].size();i++)ans[ids[x][i]]=f[x][ks[x][i]]-1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)add(read(),i);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=read();
		b=read();
		ida[a].push_back(i);
		ka[a].push_back(b);
	}
	d[0]=-1;
	dfs(0,0);
	id=g;
	f[0]=id;
	id+=(md[0]-d[0]+1);
	dfss(0,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" \n"[i==m];
	return 0;
}