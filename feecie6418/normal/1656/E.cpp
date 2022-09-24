#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,has2;
ll sum[100005],v[100005];
vector<int> g[100005];
void dfs(int x,int fa,int dep){
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x,dep+1);
		sum[x]+=sum[y];
	}
	ll mx=(dep%2?-1:1);
	for(int y:g[x]){
		if(y==fa)continue;
		v[y]=mx-sum[y];
		sum[x]+=v[y];
	}
	if(dep==2)has2=x;
}
void Solve(){
	cin>>n,has2=0;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0,0);
	if(has2){
		v[1]=sum[has2]+v[has2]+sum[g[1][0]]+v[g[1][0]]-sum[1];
	}
	else v[1]=1;
	for(int i=1;i<=n;i++){
		cout<<v[i]<<' ',assert(v[i]),assert(abs(v[i])<=1e5);
	}
	puts("");
	for(int i=1;i<=n;i++)sum[i]=v[i]=0,g[i].clear();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}