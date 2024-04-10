#include<bits/stdc++.h>
using namespace std;
#define N 75
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,A,B,k,dis[1<<17][N],id[N],ans[N];
vector<pair<int,int> > G[N];
struct Union_Set{
	int f[N];
public:
	int siz[N];
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i,siz[i]=1;
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
		siz[fx]+=siz[fy];
	}
}S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>A>>B;
	S.init(n);
	memset(dis,0x3f,sizeof(dis));
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;++i){
		id[i]=-1;
	}
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
		if(w==A){
			S.Merge(u,v);
		}
	}
	for(int i=1;i<=n;++i){
		if(S.getf(i)==i){
			if(S.siz[i]>=4){
				id[i]=k++;	
			}
		}
	}
	for(int i=1;i<=n;++i){
		id[i]=id[S.getf(i)];
	}
	queue<pair<int,int> > q1,q2;
	int beg=0;
	if(~id[1])beg=1<<id[1];
	dis[beg][1]=0;
	q1.emplace(beg,1),q2.emplace(beg,1);
	while(!q1.empty()||!q2.empty()){
		int d1=q1.empty()?inf:dis[q1.front().first][q1.front().second];
		int d2=q2.empty()?inf:dis[q2.front().first][q2.front().second];
		int s,u;
		if(d1<d2){
			s=q1.front().first,u=q1.front().second;
			q1.pop();
		}
		else{
			s=q2.front().first,u=q2.front().second;
			q2.pop();
		}
		ans[u]=min(ans[u],dis[s][u]);
		for(auto [v,w]:G[u]){
			if(w==B){
				if(S.getf(u)==S.getf(v))continue;
				if(~id[v]&&s>>id[v]&1)continue;
			}
			int t=s;
			if(~id[v])t|=1<<id[v];
			if(dis[t][v]>dis[s][u]+w){
				dis[t][v]=dis[s][u]+w;
				if(w==A)q1.emplace(t,v);
				else q2.emplace(t,v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}