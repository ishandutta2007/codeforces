#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#define P(x,y) make_pair(min(x,y),max(x,y))
#define pa pair<int,int>
#define MN 200000
#define N 262144
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pa q[MN*2+5];map<pa,bool> mp;vector<int> v[MN+5];priority_queue<pa,vector<pa>,greater<pa> > s[MN+5];
int n,m,Q,tp=0,b[MN+5],head[MN+5],dfn[MN+5],low[MN+5],mark[MN+5],dn=0,cnt=0,size[MN+5];
int fa[MN+5],w[MN+5],vis[MN+5],num=0,bel[MN+5],dep[MN+5],top[MN+5],mx[MN+5],T[N*2+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
inline void Ins(int f,int t)
{
//	cout<<"Ins"<<f<<" "<<t<<endl; 
	v[f].push_back(t);
	v[t].push_back(f);	
}
void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++dn;int son=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			if(!dfn[e[i].to]) 
			{
				++son;
				q[++tp]=make_pair(x,e[i].to),Tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
				if(low[e[i].to]>=dfn[x])
				{
					b[x]=1;++num;
					while(q[tp+1]!=make_pair(x,e[i].to))
					{
						int a=q[tp].first,b=q[tp].second;
						if(bel[a]!=num) Ins(a,num+n);
						if(bel[b]!=num) Ins(b,num+n);
						--tp;bel[a]=num;bel[b]=num;
					}
				}
			}
			else 
			{
				low[x]=min(low[x],dfn[e[i].to]);
				if(dfn[x]>dfn[e[i].to]) q[++tp]=make_pair(x,e[i].to);	
			}
		}
	if(son==1&&!fa) b[x]=0;
}

void Pre(int x,int f)
{
	fa[x]=f;size[x]=1;mx[x]=0;
	for(int i=0;i<v[x].size();++i)
		if(v[x][i]!=f)
		{
			dep[v[x][i]]=dep[x]+1;
			Pre(v[x][i],x);
			size[x]+=size[v[x][i]];
			if(size[v[x][i]]>size[mx[x]]) mx[x]=v[x][i];
		}
}

void Dfs(int x,int Tp)
{
	top[x]=Tp;dfn[x]=++dn;
	if(mx[x]) Dfs(mx[x],Tp);
	for(int i=0;i<v[x].size();++i)
		if(v[x][i]!=mx[x]&&v[x][i]!=fa[x])
			Dfs(v[x][i],v[x][i]);
}

void Renew(int x,int k){for(T[x+=N]=k;x>>=1;)T[x]=min(T[x<<1],T[x<<1|1]);}
int Query(int l,int r)
{
	int mx=1e9;	
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) mx=min(mx,T[l+1]);
		if( r&1) mx=min(mx,T[r-1]);	
	}
	return mx;
}

void Add(int x,int v,int k)
{
	++vis[v];
	s[x].push(make_pair(k,v));	
	while(!s[x].empty()&&w[s[x].top().second]!=s[x].top().first) s[x].pop();
	int K=s[x].size()?s[x].top().first:0;Renew(dfn[x],K); 
}

int Solve(int x,int y)
{
//	cout<<"Solve"<<x<<" "<<y<<endl;
	int mx=1e9;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		mx=min(mx,Query(dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	mx=min(mx,Query(dfn[x],dfn[y]));
	if(x>n&&fa[x]) mx=min(mx,w[fa[x]]);
	return mx;
}
char st[10];
int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<=n;++i) w[i]=read();
	for(int i=1;i<=m;++i) ins(read(),read());
	Tarjan(1,0);memset(T,63,sizeof(T));
	dn=0;Pre(1,0);Dfs(1,1);
//	for(int i=1;i<=n;++i) cout<<i<<" bel to "<<bel[i]<<endl;
	for(int i=1;i<=n;++i) 
	{
		Renew(dfn[i],w[i]);
		if(fa[i]) Add(fa[i],i,w[i]);
	}
	for(int i=1;i<=Q;++i)
	{
		scanf("%s",st+1);int x=read(),y=read();
		if(st[1]=='A')  printf("%d\n",Solve(x,y));
		else 
		{
			w[x]=y,Renew(dfn[x],y);
			if(fa[x]) Add(fa[x],x,y);
		}
	}
	return 0;
}