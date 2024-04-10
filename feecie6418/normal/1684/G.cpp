#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,inf=1e9;
struct Edge{
	int to,rev,flow;
};
int n,m,a[1005],S,T,dis[1005],cur[1005];
vector<Edge> g[1005];
void Add(int x,int y,int z){
	g[x].push_back({y,g[y].size(),z});
	g[y].push_back({x,g[x].size()-1,0});
}
bool bfs(){
	queue<int> q;
	for(int i=1;i<=T;i++)dis[i]=inf;
	q.push(T),dis[T]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(Edge i:g[x]){
			int y=i.to;
			if(!g[y][i.rev].flow)continue;
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1,q.push(y);
				if(y==S)return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int ret=0;
	for(int &i=cur[x];i<g[x].size();i++){
		int y=g[x][i].to;
		if(!g[x][i].flow||dis[x]!=dis[y]+1)continue;
		int w=dfs(y,min(flow,g[x][i].flow));
		g[x][i].flow-=w,g[y][g[x][i].rev].flow+=w;
		ret+=w,flow-=w;
		if(!flow)return ret;
	}
	return ret;
}
int Dinic(){
	int s=0;
	while(bfs())fill(cur+1,cur+T+1,0),s+=dfs(S,inf);
	return s;
}
pr ans[100005];
int oo=0,used[1005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	S=n+1,T=n+2;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]*2>=m)return puts("-1"),0;
		if(a[i]*3>m){
			Add(S,i,1),cnt++;
			for(int j=1;j<=n;j++){
				if(a[j]<a[i]&&a[i]%a[j]==0&&a[i]*2ll+a[j]<=m){
					Add(i,j,1);
				}
			}
		}
		else Add(i,T,1);
	}
	int w=Dinic();
	if(w!=cnt)return puts("-1"),0;
	for(int i=1;i<=n;i++){
		if(a[i]*3>m){
			for(auto j:g[i]){
				int k=j.to;
				if(k>=1&&k<=n&&!j.flow){
					ans[++oo]={2*a[i]+a[k],a[i]+a[k]};
					used[k]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)if(a[i]*3<=m&&!used[i])ans[++oo]={3*a[i],2*a[i]};
	cout<<oo<<'\n';
	for(int i=1;i<=oo;i++)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}