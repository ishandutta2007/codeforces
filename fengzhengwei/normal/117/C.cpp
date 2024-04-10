#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=5e3+5;
bitset<xx> a[xx];
int n,vis[xx],stk[xx],dfn[xx],low[xx],sz[xx],bel[xx],top,cst,scc;
deque<int>s;
void hj()
{
	if(a[s[0]][s[2]])
	{
		while(s.size()!=3)s.pop_back();
	}
	else 
	{
		int o=s.front();
		s.pop_front();s.pop_front();
		s.push_front(o);
		hj();
	}
}
void tj(int x)
{
	dfn[x]=low[x]=++cst;stk[++top]=x,vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[x][i])continue;
		int to=i;
		if(!dfn[to])tj(to),low[x]=min(low[x],low[to]);
		else if(vis[to])
		{
			while(stk[top]!=i)s.push_back(stk[top--]);
			s.push_back(stk[top--]);
			hj();
			reverse(s.begin(),s.end());
			for(auto it:s)cout<<it<<" ";
			exit(0);
		}
	}
	if(dfn[x]==low[x])
	{
		scc++;
		while(stk[top]!=x)vis[stk[top]]=0,bel[stk[top--]]=scc,sz[scc]++;
		vis[stk[top]]=0,bel[stk[top--]]=scc,sz[scc]++;
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char c;while((c=getchar())!='0'&&c!='1');
			if(c=='1')a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tj(i);
	top=0;
	puts("-1");
	return 0;
}