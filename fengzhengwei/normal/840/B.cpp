#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=3e5+5;
int n;
struct nod{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].id=z;
}
int v[xx],vis[xx],d[xx];
vector<int>ans;
void dfs(int x,int y,int z)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		dfs(e[i].to,x,e[i].id);
	}
	if(v[x]!=-1)
	{
		if(d[x]!=v[x])
		{
			if(z==0)
			{
				puts("-1");
				exit(0);
			}
			ans.push_back(z);
			d[y]^=1;
		}
	}
}
int main(){
	n=read();int m=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b,i),add(b,a,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==-1)
		{
			dfs(i,0,0);
			cout<<ans.size()<<"\n";
			for(auto it:ans)cout<<it<<"\n";
			exit(0);
		}
	}
	dfs(1,0,0);
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it<<"\n";
	pc('1',1);
	return 0;
}