#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fi first
#define sc second
typedef pair<int,int> P;
typedef pair<P,P> P2;
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
int n;
vector<int>edge[500005];
int sz[500005];
ll sum = 0;
void dfs(int v,int u,int dep){
	sum += dep+1;
	rep(i,edge[v].size()) if(edge[v][i] != u) {dfs(edge[v][i],v,dep+1);sz[v]+=sz[edge[v][i]];}
	sz[v]++;
}
ll ans;
void dfs2(int v,int u,ll cur){
ans=max(ans,cur);
	for(int i=0;i<edge[v].size();i++){
	if(edge[v][i]==u) continue;
	dfs2(edge[v][i],v,cur+n-sz[edge[v][i]]-sz[edge[v][i]]);}
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){int a,b;scanf("%d%d",&a,&b);edge[a].pb(b);edge[b].pb(a);}
	dfs(1,-1,0);
	ans = sum;
	dfs2(1,-1,sum);
	cout<<ans<<endl;}