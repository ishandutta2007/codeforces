#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#define MOD 1000000007
using namespace std;

int c[100005];
vector<int> in[100005], out[100005];
bool visited[100005];
stack<int> S;
int cLeft[100005];

void dfs(int cur){
	if(visited[cur])
		return;
	visited[cur]=true;
	for(int j=0; j < out[cur].size(); ++j){
		int to=out[cur][j];
		if(visited[to])
			continue;
		dfs(to);
	}
	S.push(cur);
}

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", c+i);
	}
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		in[b].push_back(a);
		out[a].push_back(b);
	}
	for(int i=0; i < n; ++i){
		if(visited[i])
			continue;
		dfs(i);
	}
	long long ways=1, cost=0;
	while(!S.empty()){
		int t=S.top();
		S.pop();
		if(!visited[t])
			continue;
		queue<int> q;
		q.push(t);
		vector<int> comp;
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			if(!visited[cur])
				continue;
			visited[cur]=false;
			for(int j=0; j < in[cur].size(); ++j){
				int to=in[cur][j];
				q.push(to);
			}
			comp.push_back(c[cur]);
		}
		sort(comp.begin(),comp.end());
		cost += comp[0];
		int j;
		for(j=0; j < comp.size() && comp[j] == comp[0]; ++j);
		ways=(ways*j)%MOD;
	}
	printf("%I64d %I64d\n", cost, ways);
	return 0;
}