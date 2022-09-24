#include<bits/stdc++.h>
using namespace std;
int n,a,b,da,db,mx,L,R,DIS;
vector<int> g[100005];
void dfs(int x,int fa,int dis,int &p){
	if(dis>=mx)p=x,mx=dis;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x,dis+1,p);
	}
}
void dfs2(int x,int fa,int dis,int p){
	if(x==p)DIS=dis;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs2(y,x,dis+1,p);
	}
}
void Solve(){
	cin>>n>>a>>b>>da>>db;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs2(a,0,0,b);
	if(DIS<=da){
		puts("Alice");
		return ;
	}
	mx=0,dfs(1,0,0,L);
	mx=0,dfs(L,0,0,R);
	da=min(da,mx),db=min(db,mx);
	if(db>2*da)puts("Bob");
	else puts("Alice");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
    return 0;
}