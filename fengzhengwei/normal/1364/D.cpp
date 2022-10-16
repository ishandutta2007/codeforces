#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,k;
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int dfn[xx],low[xx],stk[xx],vis[xx],V[xx],cst,tt,top;
void clear(deque<int>&s)
{
	for(int j=0;j<s.size();j++)
	{
		int x=s[j];V[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(!V[e[i].to]||(j&&e[i].to==s[j-1]))h[x]=e[i].next;
			else 
			{
				while(s[0]!=e[i].to)V[s[0]]=0,j--,s.pop_front();
				while(s[s.size()-1]!=x)s.pop_back();
			}
		}
	}
}
void dfs(int x,int y)
{
	vis[x]=1;stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(!vis[e[i].to])dfs(e[i].to,x);
		else 
		{
			deque<int>v;
//			cout<<e[i].to<<" "<<x<<" "<<vis[x]<<" "<<vis[e[i].to]<<" "<<y<<"\n";
			while(stk[top]!=e[i].to)v.push_back(stk[top--]);
			v.push_back(stk[top--]);
//			cout<<v.size()<<"\n";
//			for(auto it:v)cout<<it<<" ";puts("");
			clear(v);
			if(v.size()<=k)
			{
				puts("2");
				cout<<v.size()<<"\n";
				for(auto it:v)cout<<it<<" ";puts("");exit(0);
			}
			else 
			{
				puts("1");
				k++;k/=2;
				for(int i=1;i<=k;i++)cout<<v[(i-1)*2]<<" ";puts("");exit(0);
			}
		}
	}
	top--;
}
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst,stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tj(e[i].to,i),low[x]=min(low[x],low[e[i].to]);
		else if(i!=(y^1))low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
	{
		tt++;vector<int>v;
		while(stk[top]!=x)v.push_back(stk[top--]);
		v.push_back(stk[top--]);
		if(v.size()!=1)top=0,dfs(x,0);
	}
}
int f[xx][2],F[xx];
void dp(int x,int y)
{
	F[x]=y;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to!=y)
		{
			dp(e[i].to,x);
			f[x][0]+=max(f[e[i].to][0],f[e[i].to][1]);
			f[x][1]+=f[e[i].to][0];
		}
	}
	f[x][1]++;
}
void out(int x,int y)
{
	if(!k)exit(0);
	if(y)cout<<x<<" ",k--;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to!=F[x])
		{
			if(y==1)out(e[i].to,0);
			else 
			{
				if(f[e[i].to][0]>f[e[i].to][1])out(e[i].to,0);
				else out(e[i].to,1);
			}
		}
	}
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	tj(1,0),dp(1,0);
	k++;k/=2;
	puts("1");
//	puts("qwewqe");
	if(f[1][0]>=k)out(1,0);
	else out(1,1);
	return 0;
}