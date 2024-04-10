#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int a[2005];
int Min, Max;
vector<int> adj[2005];
bool vis[2005];
long long Ans=0;

pair<long long, long long> dfs(int node){
	if(a[node] < Min || a[node] > Max)
		return make_pair(1, 0);
	if(vis[node])
		return make_pair(1, 0);
	vis[node]=1;
	//pair<long long, long long> ans=make_pair(1, 0);
	long long ans1=1, ans2=1;
	for(int i=0; i < adj[node].size(); ++i){
		int to=adj[node][i];
		pair<long long, long long> ret=dfs(to);
		ans1=(ans1*ret.first)%MOD;
		ans2=(ans2*(ret.first-ret.second))%MOD;
		//ans=(ans*ret)%MOD;
	}
	if(a[node] == Min){
		ans2=0;
	}
	Ans=(Ans+ans1-ans2)%MOD;
	Ans=(Ans+MOD)%MOD;
	++ans1;
	++ans2;
	return make_pair(ans1, (ans1-ans2+MOD)%MOD);
}

int main(){
	int d, n;
	scanf("%d%d", &d, &n);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int i=0; i < n-1; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(Min=0; Min <= 2000; ++Min){
		Max=Min+d;
		for(int i=0; i < n; ++i)
			vis[i]=0;
		for(int i=0; i < n; ++i)
			dfs(i);
	}
	cout << Ans << endl;
}