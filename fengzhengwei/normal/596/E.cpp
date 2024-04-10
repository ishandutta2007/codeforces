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
int n,m,q;
const int xx=205;
int a[xx][xx];
int dx[10],dy[10];
struct nod{int next,to;}e[xx*xx];
int cnt,h[xx*xx];
int c(int x,int y){return (x-1)*m+y;}
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
vector<vector<int> >v;
int dfn[xx*xx],low[xx*xx],vis[xx*xx],cst;
stack<int>stk;
int vs[xx*xx];
void tarjan(int x)
{
//	cerr<<x<<"\n";
	dfn[x]=low[x]=++cst;
	stk.push(x),vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
	{
		vector<int>s;
		while(stk.top()!=x)
		{
			s.push_back(stk.top());
			vis[stk.top()]=0;
			stk.pop();
		}
		s.push_back(stk.top());
		vis[stk.top()]=0;
		stk.pop();
		if(s.size()>1)
		{
			v.push_back(s);
			for(int i=0;i<s.size();i++)vs[s[i]]=1;
		}
	}
}
char s[1000005];
int T[11];
int val[xx*xx];
int ps,len,ans;
void dfs(int x)
{
	if(s[ps]-'0'==val[x])ps++;
	if(ps==len+1)return ans=1,void();
	for(int i=h[x];i;i=e[i].next)
	{
		if(!vs[e[i].to])
		dfs(e[i].to);
		if(ans)return;
	}
	if(s[ps]-'0'==val[x])ps--;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]),val[c(i,j)]=a[i][j];
	for(int i=0;i<10;i++)dx[i]=read(),dy[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tx=i+dx[a[i][j]],ty=j+dy[a[i][j]];
			vector<int>s;
			if(tx>n||ty>m||tx<1||ty<1)s.push_back(c(i,j)),v.push_back(s),vs[c(i,j)]=1;
			else add(c(tx,ty),c(i,j));
		}
	}
	for(int i=1;i<=n*m;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		reverse(s+1,s+len+1);
		ans=0;
		for(int j=0;j<v.size();j++)
		{
			vector<int> t=v[j];
			memset(T,0,sizeof(T));
			for(int k=0;k<t.size();k++)T[val[t[k]]]=1;
			ps=1;
			while(ps<=len&&T[s[ps]-'0'])ps++;
			if(ps==len+1)ans=1;
			if(ans)break;
			for(int k=0;k<t.size();k++)
			{
				dfs(t[k]);
				if(ans)break;
			}
		}
		if(ans)puts("YES");
		else puts("NO");
	}
	return 0;
}