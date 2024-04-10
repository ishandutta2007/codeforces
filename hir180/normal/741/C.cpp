#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>edge[200005];
vector<int>edge2[200005];
int col[200005],col2[200005];
void dfs(int v,int c){
	col[v] = c;
	for(int i=0;i<edge[v].size();i++){
		if(col[edge[v][i]] != -1) continue;
		dfs(edge[v][i],1-c);
	}
}
void dfs2(int v,int c){
	col2[v] = c;
	for(int i=0;i<edge2[v].size();i++){
		if(col2[edge2[v][i]] != -1) continue;
		dfs2(edge2[v][i],1-c);
	}
}
int c[100005],d[100005];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		edge2[a].pb(b);
		edge2[b].pb(a);
		c[i] = a; d[i] = b;
	}
	for(int i=1;i<=2*n;i++){
		int j = i+1;
		if(i==2*n) j = 1;
		if(i%2 == 1){
			edge[i].pb(j);
			edge[j].pb(i);
		}
		else{
			edge2[i].pb(j);
			edge2[j].pb(i);
		}
	}
	memset(col,-1,sizeof(col));
	memset(col2,-1,sizeof(col2));
	for(int i=1;i<=2*n;i++){
		if(col[i] == -1) dfs(i,0);
	}
	for(int i=1;i<=2*n;i++){
		if(col2[i] == -1) dfs2(i,0);
	}
	bool ok = 1;
	for(int i=1;i<=2*n;i++){
		for(int j=0;j<edge[i].size();j++){
			if(col[i] == col[edge[i][j]]) ok = 0;
		}
	}
	if(ok == 1){
		for(int i=1;i<=n;i++){
			printf("%d %d\n",col[c[i]]+1,col[d[i]]+1);
		}
		return 0;
	}
	ok = 1;
	for(int i=1;i<=2*n;i++){
		for(int j=0;j<edge2[i].size();j++){
			if(col2[i] == col2[edge2[i][j]]) ok = 0;
		}
	}
	if(ok == 1){
		for(int i=1;i<=n;i++){
			printf("%d %d\n",col2[c[i]]+1,col2[d[i]]+1);
		}
		return 0;
	}
	puts("-1");
}