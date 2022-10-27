#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<int, int> > plii;

const long long inf = 1e18;
const int N = 100005;

int type[N], v[N], u[N], l[N], r[N], w[N], used[N];
vector<int> g[N], tree[N << 2];
long long dist[N];

void insert(int v, int s, int e, int l, int r, int i){
	if(l <= s && e <= r){
		tree[v].emplace_back(i);
		return;
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(l <= m)insert(v1, s, m, l, r, i);
	if(m < r)insert(v2, m + 1, e, l, r, i);
}

int query(int v, int l, int r, int i){
	while(!tree[v].empty()){
		int x = tree[v].back(); tree[v].pop_back();
		if(!used[x])return x;
	}
	if(l == r)return -1;
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)return query(v1, l, m, i);
	return query(v2, m + 1, r, i);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, s;
	cin >> n >> q >> s;
	for(int i = 1; i <= q; i++){
		cin >> type[i];
		if(type[i] == 1){
			cin >> v[i] >> u[i] >> w[i];
		}else{
			cin >> v[i] >> l[i] >> r[i] >> w[i];
		}
		if(type[i] <= 2){
			g[v[i]].emplace_back(i);
		}else{
			insert(1, 1, n, l[i], r[i], i);
		}
	}
	set<int> unvisited;
	for(int i = 1; i <= n; i++){
		unvisited.insert(i);
		dist[i] = inf;
	}
	priority_queue<plii, vector<plii>, greater<plii> >pq;
	dist[s] = 0; pq.push({0, {s, s}});
	while(!pq.empty()){
		long long cur = pq.top().first;
		int lo = pq.top().second.first;
		int hi = pq.top().second.second;
		pq.pop();

		auto it = unvisited.lower_bound(lo);
		while(it != unvisited.end() && (*it) <= hi){
			int x = *it; ++it;
			dist[x] = cur;
			for(int i : g[x]){
				if(type[i] == 1){
					if(dist[u[i]] > dist[x] + w[i]){
						dist[u[i]] = dist[x] + w[i];
						pq.push({dist[u[i]], {u[i], u[i]}});
					}
				}else{
					pq.push({dist[x] + w[i], {l[i], r[i]}});
				}
			}
			while(true){
				int ind = query(1, 1, n, x);
				if(ind == -1)break;
				if(dist[v[ind]] > dist[x] + w[ind]){
					dist[v[ind]] = dist[x] + w[ind];
					pq.push({dist[v[ind]], {v[ind], v[ind]}});
				}
				used[ind] = 1;
			}
			unvisited.erase(x);
		}
	}
	for(int i = 1; i <= n; i++){
		if(dist[i] < inf){
			cout << dist[i] << " ";
		}else{
			cout << -1 << " ";
		}
	}
	cout << '\n';

	return 0;
}