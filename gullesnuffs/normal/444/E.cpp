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

int xsum;
int x[3005];
vector<pair<int, int> > adj[3005];
bool vis[3005];
vector<pair<int, int> > comp;
int limit;
int xx, nn;

void dfs(int node){
	if(vis[node])
		return;
	vis[node]=1;
	for(int i=0; i < adj[node].size(); ++i){
		if(adj[node][i].second > limit)
			continue;
		dfs(adj[node][i].first);
	}
	xx += x[node];
	nn += 1;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n-1; ++i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	for(int i=0; i < n; ++i){
		scanf("%d", x+i);
		xsum += x[i];
	}
	int lo=-1, hi=10005;
	while(hi-lo > 1){
		int mid=(hi+lo)/2;
		limit=mid;
		bool ok=1;
		for(int i=0; i < n; ++i)
			vis[i]=0;
		for(int i=0; i < n; ++i){
			if(xsum < n){
				ok=0;
				break;
			}
			xx=0;
			nn=0;
			dfs(i);
			if(nn){
				if(xsum-xx < nn){
					ok=0;
					break;
				}
			}
		}
		if(ok)
			lo=mid;
		else
			hi=mid;
	}
	printf("%d\n", hi);
	return 0;
}