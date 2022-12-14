#include<iostream>
#include<cstdio>
#include<vector>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<pair<int,int> >v[MN+5];long long Ans[MN+5],s[MN+5];
int n,m,Q,head[MN+5],cnt=1,L[MN+5],q[MN+5],top,vis[MN+5],inq[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}	

void dfs(int x,int fa)
{
	vis[x]=1;q[++top]=x;inq[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(i!=fa) 
		{
			if(!vis[e[i].to]) dfs(e[i].to,i^1);
			else if(inq[e[i].to])
			{
				int j=top,mn=e[i].to,mx=e[i].to;
				while(q[j]!=e[i].to) mx=max(mx,q[j]),mn=min(mn,q[j]),--j;
				L[mx]=max(L[mx],mn);//cout<<"Find"<<mx<<" "<<mn<<endl;
			}
		}
	inq[x]=0;--top;
}
#define S(x) 1LL*(x)*((x)+1)/2
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) ins(read(),read());
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,0);
	Q=read();
	for(int i=1;i<=Q;++i)
	{
		int l=read(),r=read();
		v[r].push_back(make_pair(l,i));
	}
	for(int i=1,j=0;i<=n;++i)
	{
		while(j<L[i]) s[j+1]=s[j]+i-1,++j; L[i]=j;
		for(int j=0;j<v[i].size();++j)
		{
		//	cout<<i<<" "<<v[i][j].first<<" "<<L[i]<<endl;
			Ans[v[i][j].second]=S(i-v[i][j].first+1);
			//cout<<"preans="<<Ans[v[i][j].second]<<endl;
		//	cout<<s[L[i]]<<" "<<s[v[i][j].first-1]<<endl;
			if(v[i][j].first<=L[i]) 
				Ans[v[i][j].second]-=1LL*(L[i]-v[i][j].first+1)*i-(s[L[i]]-s[v[i][j].first-1]);
		}
	}
	for(int i=1;i<=Q;++i) printf("%lld\n",Ans[i]);
	return 0;
}