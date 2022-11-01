#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],b[N],dis[N],pre[N],jb[N];
set<int> S;
void dfs(int u){
	if(u==n)return;
	dfs(pre[u]);
	cout<<jb[u]<<' ';	
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	for(int i=0;i<n;++i){
		S.insert(i);
		dis[i]=inf;	
	}
	for(int i=0;i<=n;++i)pre[i]=0;
	dis[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		while(true){
			auto it=S.upper_bound(u);
			if(it==S.begin())break;
			--it;
			if((*it)<u-a[u])break;
			int v=(*it)+b[*it];
			if(dis[v]==inf){
				dis[v]=dis[u]+1;
				q.push(v);
				pre[v]=u;
				jb[v]=*it;
			}	
			S.erase(it);
		}
	}
	if(dis[0]==inf){
		cout<<-1<<'\n';
	}
	else{
		cout<<dis[0]<<'\n';
		dfs(0);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}