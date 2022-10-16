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
int n;
const int xx=100005;
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
vector<int>S;
int vis[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	S.push_back(x);
	h[x]=cnt;
	e[cnt].to=y;
}
void clear()
{
	for(int i=0;i<S.size();i++)h[S[i]]=vis[S[i]]=0;
	S.clear();
}
int f[xx][21],dep[xx],dfx[xx],cst;
void dfs(int x,int y)
{
	f[x][0]=y;dep[x]=dep[y]+1;dfx[x]=++cst;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);	
	while(dep[x]!=dep[y])x=f[x][int(log2(dep[x]-dep[y]))];
	if(x==y)return x;
	for(int i=log2(dep[x]);i>=0;i--)(f[x][i]^f[y][i])?x=f[x][i],y=f[y][i]:0;
	return f[x][0];
}
int stk[xx],tot;
bool cmp(const int&x,const int&y){return dfx[x]<dfx[y];}
int check(int x)
{
	for(int i=h[x];i;i=e[i].next)if(check(e[i].to))return 1;
	for(int i=h[x];i;i=e[i].next)if(vis[x]&&vis[e[i].to]&&dep[e[i].to]==dep[x]+1)return 1;
	return 0;
}
int dp(int x)
{
	int s=0,t=0;
	for(int i=h[x];i;i=e[i].next)s+=dp(e[i].to),t+=vis[e[i].to];
	if(vis[x])s+=t;
	else if(t>1)s++;
	else vis[x]=t;
	return s;
}
signed main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a); 
	}
	dfs(1,0);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
	int m=read();
	while(m--)
	{
		int q=read();
		vector<int>v;
		for(int i=1;i<=q;i++)v.push_back(read());
		sort(v.begin(),v.end(),cmp);
		tot=0;
		stk[++tot]=1;
		memset(e,0,sizeof(e[0])*(cnt+1));
		clear();cnt=0;
		for(int i=0;i<q;i++)vis[v[i]]=1;
		for(int i=0;i<q;i++)
		{
			int a=v[i],b=lca(a,stk[tot]);

			if(a==1)continue;
			while(dep[b]<dep[stk[tot]])
			{
				if(dep[b]>=dep[stk[tot-1]])
				{
					if(b!=stk[tot-1])
					{
						add(b,stk[tot]);
						stk[tot]=b;
						break;
					}
				}
				add(stk[tot-1],stk[tot]);
				tot--;
			}
			stk[++tot]=a;
		}
		while(tot!=1)add(stk[tot-1],stk[tot]),tot--;
		if(check(1))puts("-1");
		else cout<<dp(1)<<"\n";
		for(int i=0;i<q;i++)vis[v[i]]=0;
	}
	return 0;
}