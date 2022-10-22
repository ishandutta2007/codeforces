#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,l,r,u[MAXN],v[MAXN],w[MAXN],dep[MAXN],dis[MAXN],siz[MAXN],sum,mxsiz,rt;pair<int,int>mx[MAXN],nowmx[MAXN],res;bool vis[MAXN];vector<pair<int,int>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void getrt(int u,int f){siz[u]=1;int mx=0;for(auto v:E[u])if(v.first!=f&&!vis[v.first])getrt(v.first,u),siz[u]+=siz[v.first],mx=max(mx,siz[v.first]);if(max(mx,sum-siz[u])<mxsiz)mxsiz=max(mx,sum-siz[u]),rt=u;}
void getdis(int u,int f){siz[u]=1;dep[u]=dep[f]+1;mx[dep[u]]=max(mx[dep[u]],{dis[u],u});for(auto v:E[u])if(v.first!=f&&!vis[v.first])dis[v.first]=dis[u]+v.second,getdis(v.first,u),siz[u]+=siz[v.first];}
void solve(int u)
{
	vis[u]=1;int K=0;
	for(auto v:E[u])if(!vis[v.first])
	{
		dis[v.first]=v.second;dep[u]=0;getdis(v.first,u);int M=1;while(mx[M].first>-N)M++;M--;deque<int>q;
		For(i,1,M)if(mx[i].first>=0&&i>=l&&i<=r){res={u,mx[i].second};break;}
		if(res.first&&res.second){For(i,1,M)mx[i]={-N,0};break;}
		For(i,1,min(r,M))
		{
			while(!q.empty()&&q.front()+i>r)q.pop_front();
			if(i<l){while(!q.empty()&&nowmx[l-i]>nowmx[q.back()])q.pop_back();q.push_back(l-i);}
			if(!q.empty()&&mx[i].first+nowmx[q.front()].first>=0){res={mx[i].second,nowmx[q.front()].second};break;}
		}
		K=max(K,M);For(i,1,M)nowmx[i]=max(nowmx[i],mx[i]),mx[i]={-N,0};if(res.first&&res.second)break;
	}
	if(res.first&&res.second){For(i,1,K)nowmx[i]={-N,0};return;}For(i,1,K)nowmx[i]={-N,0};
	for(auto v:E[u])if(!vis[v.first]){if(siz[v.first]<=l)continue;sum=mxsiz=siz[v.first];getrt(v.first,0);solve(rt);if(res.first&&res.second)break;}
}
bool check(int x)
{
	res={0,0};For(i,1,N)E[i].clear(),vis[i]=0;For(i,1,N-1)E[u[i]].push_back({v[i],w[i]>=x?1:-1}),E[v[i]].push_back({u[i],w[i]>=x?1:-1});
	sum=mxsiz=N;getrt(1,0);res={0,0};solve(rt);if(res.first&&res.second)return 1;return 0;
}
int main()
{
	N=get(),l=get(),r=get();For(i,1,N-1)u[i]=get(),v[i]=get(),w[i]=get();For(i,0,N)mx[i]=nowmx[i]={-N,0};
	int l=0,r=1e9;pair<int,int>ans;while(l<=r){int mid=l+r>>1;check(mid)?ans=res,l=mid+1:r=mid-1;}cout<<ans.first<<' '<<ans.second<<'\n';return 0;
}