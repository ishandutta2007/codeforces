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
#include <cassert>
using namespace std;

int n, m, k;
vector<pair<int, int> > road[300005];
vector<pair<int, int> > train;
long long disToCap[100005];
long long d[300005];
pair<long long, int> sorted[100005];
int trainN[100005];
bool vis[100005];


int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i < n; ++i)
		disToCap[i]=1000000001LL;
	for(int i=0; i < m; ++i){
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		--u;
		--v;
		road[u].push_back(make_pair(v, x));
		road[v].push_back(make_pair(u, x));

	}
	for(int i=0; i < k; ++i){
		int s, y;
		scanf("%d%d", &s, &y);
		--s;
		train.push_back(make_pair(s, y));
		disToCap[s]=min((int)(disToCap[s]), y);
		++trainN[s];
	}
	disToCap[0]=0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	for(int i=0; i < n; ++i){
		d[i]=disToCap[i];
		q.push(make_pair(-d[i], i));
	}
	while(!q.empty()){
		int node=q.top().second;
		long long dis=-q.top().first;
		q.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(int i=0; i < road[node].size(); ++i){
			int to=road[node][i].first;
			int len=road[node][i].second;
			if(dis+len < d[to]){
				d[to]=dis+len;
				q.push(make_pair(-d[to], to));
			}
		}
	}
	for(int i=0; i < n; ++i)
		sorted[i]=make_pair(d[i], i);
	sort(sorted, sorted+n);
	int ans=0;
	for(int i=0; i < n; ++i){
		if(!trainN[sorted[i].second])
			continue;
		int node=sorted[i].second;
		int minDis=1000000001LL;
		for(int j=0; j < road[node].size(); ++j){
			int to=road[node][j].first;
			int len=road[node][j].second;
			minDis=min(minDis, (int)(len+d[to]));
		}
		if(minDis == d[node])
			ans++;
		ans += trainN[node]-1;
	}
	printf("%d\n", ans);
	return 0;
}