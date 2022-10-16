#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int dfn[xx],low[xx],stk[xx],vis[xx],ans[xx<<1],cst,top;
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst,stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])
		{
			tj(e[i].to,i),low[x]=min(low[x],low[e[i].to]);
			if(low[e[i].to]>=dfn[x])
			{
				vector<int>v;
				while(stk[top]!=e[i].to)v.push_back(stk[top--]);
				v.push_back(stk[top--]);
				for(auto it:v)vis[it]=1;
				vis[x]=1;
				
				int o=0;
				for(auto it:v)
					for(int j=h[it];j;j=e[j].next)if(vis[e[j].to])o++,o+=(e[j].to==x);
//				puts("!!!! ");
//				for(auto it:v)cout<<it<<" ";
//				cout<<o<<"\n";
//				puts("END");
//				puts("");
				o/=2;
				
				if(o==v.size()+1){for(auto it:v)for(int j=h[it];j;j=e[j].next)if(vis[e[j].to])ans[j]=ans[j^1]=1;}
				vis[x]=0;
				
				for(auto it:v)vis[it]=0;
			}
		}
		else if(i!=(y^1))low[x]=min(low[x],dfn[e[i].to]);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tj(i,0);
	int tt=0;
	for(int i=1;i<=m;i++)if(ans[i*2])tt++;
	cout<<tt<<"\n";
	for(int i=1;i<=m;i++)if(ans[i*2])cout<<i<<" ";puts("");
	return 0;
}