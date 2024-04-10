#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
struct node{int to[26],fail;}e[xx];
char s[xx];
string S[xx];
int cst=1;
int c(int &x){return !x?(x=++cst):x;}
int insert()
{
	int p=strlen(s),last=1;
	for(int i=0;i<p;i++)last=c(e[last].to[s[i]-'a']);
	return last;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(e[1].to[i])e[e[1].to[i]].fail=1,q.push(e[1].to[i]);
		else e[1].to[i]=1;
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(!e[x].to[i])e[x].to[i]=e[e[x].fail].to[i];
			else e[e[x].to[i]].fail=e[e[x].fail].to[i],q.push(e[x].to[i]);
		}
	}
}
int ed[xx],sz[xx];
struct query{int id,op,v;};
vector<query>q1[xx],q2[xx];
int dfx[xx],size[xx],YY;
namespace G
{
	struct node{int next,to;}e[xx*2];
	int cnt,h[xx];
	void add(int x,int y)
	{
		cnt++;
		e[cnt].next=h[x];
		h[x]=cnt;
		e[cnt].to=y;
	}
	void dfs(int x,int y)
	{
		size[x]=1,dfx[x]=++YY;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dfs(e[i].to,x);
			size[x]+=size[e[i].to];
		}
	}
}
const int B=1822;//1822.6157288049947989975599516708
const int Bs=317;
int val[xx],tg[xx];
int bel(int x){return (x-1)/Bs+1;}
void cg(int x,int y)
{
	if(bel(x)==bel(y))
		for(int i=x;i<=y;i++)val[i]++;
	else 
	{
		for(int i=x;i<=bel(x)*Bs;i++)val[i]++;
		for(int i=bel(y)*Bs-Bs+1;i<=y;i++)val[i]++;
		for(int i=bel(x)+1;i<bel(y);i++)tg[i]++;
	}
}
int get(int x){return val[x]+tg[bel(x)];}
int lb(int x){return x&-x;}
int sum[xx];
void add(int x,int y){for(;x<=cst;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
ll ans[xx];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ed[i]=insert();
		sz[i]=strlen(s);
		S[i]=s;
	}
	getfail();
	for(int i=2;i<=cst;i++)G::add(e[i].fail,i);
	G::dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),k=read();
		if(sz[k]<=B)q1[r].push_back((query){i,1,k}),q1[l-1].push_back((query){i,-1,k});
		else q2[k].push_back((query){i,1,r}),q2[k].push_back((query){i,-1,l-1});
	}
	for(int i=1;i<=n;i++)
	{
		cg(dfx[ed[i]],dfx[ed[i]]+size[ed[i]]-1);
		for(int j=0;j<q1[i].size();j++)
		{
			int x=q1[i][j].v,last=1;
			for(int k=0;k<sz[x];k++)
			{
				last=e[last].to[S[x][k]-'a'];
				ans[q1[i][j].id]+=q1[i][j].op*get(dfx[last]);
			}
		}
		q1[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		if(!q2[i].size())continue;
		memset(sum,0,sizeof(sum));
		int last=1;
		for(int k=0;k<sz[i];k++)
		{
			last=e[last].to[S[i][k]-'a'];
			add(dfx[last],1);
		}
		for(int k=0;k<q2[i].size();k++)q1[q2[i][k].v].push_back(q2[i][k]);
		ll res=0;
		for(int j=1;j<=n;j++)
		{
			res+=ask(dfx[ed[j]]+size[ed[j]]-1)-ask(dfx[ed[j]]-1);
			for(int k=0;k<q1[j].size();k++)ans[q1[j][k].id]+=q1[j][k].op*res;
		}
		for(int k=0;k<q2[i].size();k++)q1[q2[i][k].v].pop_back();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}