#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

long long dist[2*maxn];
vector<array<int, 3> > g[2*maxn];
int x[maxn], d[maxn], t[maxn], p[maxn], par[2*maxn], vis[2*maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int L; cin >> L;
	vector<int> vec;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> d[i] >> t[i] >> p[i];
		vec.emplace_back(x[i] + d[i]);
		if(x[i] >= p[i])vec.emplace_back(x[i] - p[i]);
	}
	vec.emplace_back(0);
	vec.emplace_back(L);
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

	int m = (int)vec.size();
	for(int i = 0; i < n; i++){
		if(x[i] < p[i])continue;
		int ind1 = lower_bound(vec.begin(), vec.end(), x[i] - p[i]) - vec.begin();
		int ind2 = lower_bound(vec.begin(), vec.end(), x[i] + d[i]) - vec.begin();
		g[ind1].push_back({ind2, p[i] + t[i], i});
	}
	for(int i = 0; i < m; i++){
		vis[i] = 0;
		par[i] = -1;
		dist[i] = (long long)1e15;
	}
	priority_queue<pair<long long, int> > qu;
	qu.push({0, 0}); dist[0] = 0;
	while(!qu.empty()){
		int v = qu.top().second; qu.pop();
		if(vis[v])continue;
		vis[v] = 1;

		if(v > 0 && dist[v - 1] > dist[v] + vec[v] - vec[v - 1]){
			dist[v - 1] = dist[v] + vec[v] - vec[v - 1];
			qu.push({-dist[v - 1], v - 1});
			par[v - 1] = -2;
		}
		if(v + 1 < m && dist[v + 1] > dist[v] + vec[v + 1] - vec[v]){
			dist[v + 1] = dist[v] + vec[v + 1] - vec[v];
			qu.push({-dist[v + 1], v + 1});
			par[v + 1] = -3;
		}
		for(auto x : g[v]){
			if(dist[x[0]] > dist[v] + x[1]){
				dist[x[0]] = dist[v] + x[1];
				qu.push({-dist[x[0]], x[0]});
				par[x[0]] = x[2];
			}
		}
	}
	assert(dist[m - 1] <= L);
	cout << dist[m - 1] << '\n';
	vector<int> ramps;
	int cur = m - 1;
	while(cur != 0){
		if(par[cur] == -2){
			cur++;
		}else if(par[cur] == -3){
			cur--;
		}else{
			assert(par[cur] >= 0);
			int i = par[cur];
			int ind1 = lower_bound(vec.begin(), vec.end(), x[i] - p[i]) - vec.begin();
			int ind2 = lower_bound(vec.begin(), vec.end(), x[i] + d[i]) - vec.begin();
			assert(ind2 == cur);
			cur = ind1;
			ramps.emplace_back(i);
		}
	}
	reverse(ramps.begin(), ramps.end());
	cout << (int)ramps.size() << '\n';
	for(auto x : ramps){
		cout << x + 1 << '\n';
	}

	return 0;
}