#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector<int> ga[N], gb[N];
int ptr, st[N], en[N];

void dfs(int v){
	st[v] = ptr++;
	for(int u : gb[v]){
		dfs(u);
	}
	en[v] = ptr - 1;
}

set<array<int, 2> > blocks;
int answer;

void compute(int v){
	array<int, 2> rem({-1, -1});
	bool added = true;
	if(!blocks.empty()){
		auto it = blocks.lower_bound({st[v], -1});
		if(it != blocks.end()){
			int lo = (*it)[0];
			int hi = (*it)[1];
			if(st[v] <= lo && hi <= en[v]){
				added = false;
			}
		}
		if(added && it != blocks.begin()){
			--it;
			int lo = (*it)[0];
			int hi = (*it)[1];
			if(lo <= st[v] && en[v] <= hi){
				rem = *it;
				blocks.erase(rem);
			}
		}
	}
	if(added){
		blocks.insert({st[v], en[v]});
	}
	answer = max(answer, (int)blocks.size());
	for(int u : ga[v]){
		compute(u);
	}
	if(added){
		blocks.erase({st[v], en[v]});
	}
	if(rem[0] != -1){
		blocks.insert(rem);
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ga[i].clear();
		gb[i].clear();
	}
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		ga[p].push_back(i);
	}
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		gb[p].push_back(i);
	}
	ptr = 1; dfs(1);
	blocks.clear();
	answer = 1;
	compute(1);
	cout << answer << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}