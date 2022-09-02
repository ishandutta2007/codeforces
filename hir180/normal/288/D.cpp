#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int>edge[80005]; int cnt[80005];
unsigned long long ret;
int n;
void dfs(int v,int u)
{
	cnt[v]=1;
	unsigned long long val=1ull*n*(n-1)/2ull;
	for(int i=0;i<edge[v].size();i++)
	{
		int to=edge[v][i]; if(to == u) continue;
		dfs(to,v); val-=1ull*cnt[to]*(cnt[to]-1)/2ull; cnt[v]+=cnt[to];
	}
	val-=1ull*(n-cnt[v])*(n-cnt[v]-1)/2ull;
	ret-=(val*val-(1ull*(n-cnt[v])*cnt[v])*(1ull*(n-cnt[v])*cnt[v]));
}
int main()
{
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	ret=1ull*n*(n-1)/2ull;
	ret*=ret;
	dfs(rand()%n+1,-1);
	cout << ret << endl;
}