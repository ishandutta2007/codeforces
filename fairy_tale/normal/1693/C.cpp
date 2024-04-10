#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> deg(n);
	vector<vector<int>> gph(n);
	for(int i = 0; i < m; i++){
		int s, e; cin >> s >> e;
		s--; e--;
		deg[s]++;
		gph[e].push_back(s);
	}
	vector<lint> dist(n, 1e18);
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	auto enq = [&](int x, lint v){
		if(dist[x] > v){
			dist[x] = v;
			pq.emplace(dist[x], x);
		}
	};
	enq(n - 1, 0);
	while(sz(pq)){
		auto x = pq.top();
		pq.pop();
		if(dist[x.second] != x.first) continue;
		for(auto &y : gph[x.second]){
			deg[y]--;
			enq(y, x.first + deg[y] + 1);
		}
	}
	cout << dist[0] << "\n";
}