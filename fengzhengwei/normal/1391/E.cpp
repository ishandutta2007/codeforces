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
int T,n,m;
const int xx=1e6+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx],vis[xx],dep[xx];
vector<int>v[xx];
void dfs(int x,int y)
{
//	cout<<x<<"SSSSS\n";
	f[x]=y;vis[x]=1;dep[x]=dep[y]+1;v[dep[x]].push_back(x);
	for(int i=h[x];i;i=e[i].next)
		if(!vis[e[i].to])dfs(e[i].to,x);
}
signed main(){
	T=read();
	while(T--)
	{
		n=read(),m=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
		}
//		puts("qweqe");
		memset(vis,0,sizeof(vis[0])*(n+1));
		for(int i=1;i<=n;i++)v[i].clear();
		dfs(1,0);
		vector<int>ans;
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			if(dep[i]>=(n+1)/2)
			{
//				puts("QWeqe");
				vis=1;
				int x=i;
				while(x)ans.push_back(x),x=f[x];
				break;
			}
		}
		if(vis)
		{
			puts("PATH");
			cout<<ans.size()<<"\n";
			for(auto it:ans)cout<<it<<" ";
			puts("");continue;
		}
		vector<pair<int,int> >res;
		for(int i=1;i<=n;i++)
		{
//			cout<<i<<" "<<v[i].size()<<"!!!\n";
			for(int j=0;j<v[i].size();j+=2)
				if(j+1!=v[i].size())res.push_back(make_pair(v[i][j],v[i][j+1]));
		}
		puts("PAIRING");
		cout<<res.size()<<"\n";
		for(auto it:res)cout<<it.first<<" "<<it.second<<"\n";
		puts("");continue;
	}
	return 0;
}