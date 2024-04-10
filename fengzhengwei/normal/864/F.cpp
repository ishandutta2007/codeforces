#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=3005;
vector<int>v[xx],t[xx];
struct qq{int id,x,k;};
vector<qq> q[xx];
int n,m,rc[xx],stk[xx],top;
void dfs(int x)
{
	rc[x]=1;
	for(auto it:t[x])
		if(!rc[it])dfs(it);
}
int vis[xx],f[xx][13],ans[xx*xx];
signed main(){
	n=read(),m=read();
	int qs=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b);
		t[b].push_back(a);
	}
	for(int i=1;i<=qs;i++)
	{
		int a=read(),b=read(),k=read();
		q[b].push_back((qq){i,a,k});
	}
	for(int i=1;i<=n;i++)
	{
		memset(rc,0,sizeof(rc));
		memset(f,0,sizeof(f));
		dfs(i);
		for(int j=1;j<=n;j++)
		{
			if(!rc[j])continue;
			int mn=1e9;
			for(auto it:v[j])
				if(rc[it])mn=min(it,mn);
			f[j][0]=mn;
		}
		f[i][0]=0;
		for(int j=1;j<=12;j++)
			for(int x=1;x<=n;x++)
				f[x][j]=f[f[x][j-1]][j-1];
		for(auto it:q[i])
		{
			if(f[it.x][12]||!rc[it.x])ans[it.id]=-1;
			else 
			{
				int o=it.k-1,x=it.x;
				for(int j=11;j>=0;j--)
					if(o>>j&1)x=f[x][j];
				if(!x)ans[it.id]=-1;
				else ans[it.id]=x;
			}
		}
	}
	for(int i=1;i<=qs;i++)cout<<ans[i]<<"\n";
    return 0;
}