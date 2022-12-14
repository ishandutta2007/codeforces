#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<pair<int,int> > occ[MN+5];
int n,m,head[MN+5],cnt=1,res[MN+5],flag,vis[MN+5],mark[MN+5],q[MN+5],top;
struct edge{int to,next,id,w;}e[MN*2+5];
inline void ins(int f,int t,int d,int w){e[++cnt]=(edge){t,head[f],d,w};head[f]=cnt;}

void Mark(int x)
{
	mark[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!mark[e[i].to])
		{
			res[e[i].id]=e[i].w;
			Mark(e[i].to);
		}	
}

void Solve(vector<int> v)
{
	if(flag) return;flag=1;
//	cout<<"Solve";
	for(int i=0;i<v.size();++i)
	{
	//	cout<<v[i]<<endl;
		int nx=(i==v.size()-1)?v[0]:v[i+1];
		mark[v[i]]=1;
		for(int j=head[v[i]];j;j=e[j].next)
			if(e[j].to==nx&&!res[e[j].id])
			{
			//	cout<<"set"<<e[j].id<<" "<<e[j].w<<endl;
				res[e[j].id]=e[j].w;
				break;
			}
	}
	for(int i=0;i<v.size();++i) Mark(v[i]);
}

void dfs(int x,int fa)
{
	if(flag) return;vis[q[++top]=x]=1;
	for(int i=head[x];i&&!flag;i=e[i].next)
		if(i!=fa)
		{
			if(vis[e[i].to])
			{
				vector<int> v;
				for(;q[top+1]!=e[i].to;--top) v.push_back(q[top]);
				Solve(v); 
			}
			else 
				dfs(e[i].to,i^1);
		}
	--top;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=read();j;--j)
		{
			int x=read();
			if(x>0) occ[x].push_back(make_pair(i,1));
			else occ[-x].push_back(make_pair(i,-1));	
		}
	for(int i=1;i<=m;++i) if(occ[i].size())
	{
		if(occ[i].size()==1||(occ[i][0].second==occ[i][1].second))
			for(int j=0;j<occ[i].size();++j) ins(occ[i][j].first,occ[i][j].first,i,occ[i][j].second),++cnt;	
		else 
		{
			int x,y;
			if(occ[i][0].second<0) x=occ[i][1].first,y=occ[i][0].first;
			else x=occ[i][0].first,y=occ[i][1].first;
			ins(y,x,i,1);ins(x,y,i,-1); 	
		}
	}
	for(int i=1;i<=n;++i) if(!vis[i]&&!mark[i])
	{	
		top=flag=0;dfs(i,0);
		if(!flag) return 0*puts("NO");	
	}
	puts("YES");
	for(int i=1;i<=m;++i) printf("%d",res[i]==1?res[i]:0);
	return 0;
}