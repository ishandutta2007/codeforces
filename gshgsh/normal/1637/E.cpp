#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int T,N,M,a[MAXN],b[MAXN],x[MAXN],y[MAXN],c[MAXN],d[MAXN],e[MAXN];vector<int>pos[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=b[i]=get();For(i,1,M)x[i]=get(),y[i]=get();
		sort(b+1,b+N+1);int K=unique(b+1,b+N+1)-b-1;
		For(i,1,N)a[i]=lower_bound(b+1,b+K+1,a[i])-b;For(i,1,M)x[i]=lower_bound(b+1,b+K+1,x[i])-b,y[i]=lower_bound(b+1,b+K+1,y[i])-b;
		For(i,1,N)c[i]=0;For(i,1,N)c[a[i]]++;
		For(i,1,K)d[i]=c[i];sort(d+1,d+K+1);int K2=unique(d+1,d+K+1)-d-1;For(i,1,K2)e[d[i]]=i,pos[i].clear();
		For(i,1,K)pos[e[c[i]]].push_back(i);ll ans=0;
		map<pair<int,int>,bool>vis;For(i,1,M)vis[{x[i],y[i]}]=vis[{y[i],x[i]}]=1;
		For(i,1,K2)
		{
			auto x=pos[i];int M=x.size();if(M<=1)continue;
			priority_queue<pair<int,pair<int,int>>>q;q.push({b[x[M-1]]+b[x[M-2]],{M-1,M-2}});
			map<pair<int,int>,bool>in;in[{M-1,M-2}]=1;
			while(!q.empty())
			{
				auto u=q.top();q.pop();int m=u.second.first,n=u.second.second;
				if(!vis[{x[m],x[n]}]){ans=max(ans,2ll*d[i]*(b[x[m]]+b[x[n]]));break;}
				if(!in.count({m,n-1})&&n>0)q.push({b[x[m]]+b[x[n-1]],{m,n-1}}),in[{m,n-1}]=1;
				if(!in.count({m-1,n})&&m-1>n)q.push({b[x[m-1]]+b[x[n]],{m-1,n}}),in[{m-1,n}]=1;
			}
		}
		For(i,1,K2)For(j,i+1,K2)
		{
			int M1=pos[i].size(),M2=pos[j].size();
			priority_queue<pair<int,pair<int,int>>>q;q.push({b[pos[i][M1-1]]+b[pos[j][M2-1]],{M1-1,M2-1}});
			map<pair<int,int>,bool>in;in[{M1-1,M2-1}]=1;
			while(!q.empty())
			{
				auto u=q.top();q.pop();int m=u.second.first,n=u.second.second;
				if(!vis[{pos[i][m],pos[j][n]}]){ans=max(ans,1ll*(d[i]+d[j])*(b[pos[i][m]]+b[pos[j][n]]));break;}
				if(m>0&&!in.count({m-1,n}))q.push({b[pos[i][m-1]]+b[pos[j][n]],{m-1,n}}),in[{m-1,n}]=1;
				if(n>0&&!in.count({m,n-1}))q.push({b[pos[i][m]]+b[pos[j][n-1]],{m,n-1}}),in[{m,n-1}]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}