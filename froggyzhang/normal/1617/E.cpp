#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define M 6000060
typedef long long ll;
typedef pair<int,int> pii;
int n,a[N],cnt;
vector<int> G[M];
unordered_map<int,int> mp;
int id[M];
void Link(int x){
	if(!x)return;
	int u=x,v=(1<<(int)ceil(log2(x)))-x;
	if(!mp.count(u))mp[u]=++cnt;
	if(!mp.count(v))mp[v]=++cnt;
	Link(v);
	u=mp[u],v=mp[v];
	G[u].push_back(v);
	G[v].push_back(u);
}
pair<int,int> bfs(int S){
	static int dis[M];
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	dis[S]=0;
	pii ans=pii(-1,-1);
	q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(id[u]){
			ans=max(ans,pii(dis[u],u));
		}
		for(auto v:G[u]){
			if(!~dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	mp[0]=++cnt;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		Link(a[i]);
		id[mp[a[i]]]=i;
	}
	int X=bfs(mp[0]).second;
	auto [D,Y]=bfs(X);
	cout<<id[X]<<' '<<id[Y]<<' '<<D<<'\n';
	return 0;
}