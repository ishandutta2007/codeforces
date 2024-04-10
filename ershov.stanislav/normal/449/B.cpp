#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>

#define pb push_back
#define mp make_pair

using namespace std;

int n, m, k;
bool train[111111];
vector<pair<int, pair<int, int> > > g[111111];
vector<int> type[111111];
long long dist[111111];
set<pair<long long, int> > dijk;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<m; i++) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		g[u].pb(mp(x, mp(v, 0))), g[v].pb(mp(x, mp(u, 0)));
	}
	for (int i=0; i<k; i++) {
		int s, y;
		scanf("%d%d", &s, &y);
		g[1].pb(mp(y, mp(s, 1)));
		g[s].pb(mp(y, mp(1, 1)));
		train[s]=true;
	}
	for (int i=2; i<=n; i++) dist[i]=1e15;
	dijk.insert(mp(0, 1));
	while (dijk.size()) {
		pair<long long, int> now=*dijk.begin();
		dijk.erase(dijk.begin());
		sort(g[now.second].begin(), g[now.second].end());
		for (int i=0; i<g[now.second].size(); i++) if (dist[g[now.second][i].second.first]>=now.first+g[now.second][i].first){
			dijk.erase(mp(dist[g[now.second][i].second.first], g[now.second][i].second.first));
			dist[g[now.second][i].second.first]=now.first+g[now.second][i].first;
			dijk.insert(mp(dist[g[now.second][i].second.first], g[now.second][i].second.first));
			if (now.second!=1||!g[now.second][i].second.second) train[g[now.second][i].second.first]=false;
		}
	}
	for (int i=0; i<=n; i++) if (train[i]) k--;
	cout << k;
	return 0;
}