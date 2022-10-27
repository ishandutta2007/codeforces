#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

set<int> adj[N];
int n, q, f[N], sz[N];
long long t[N], income[N];
set<pair<long long, int> > globalIncomeSet, chIncome[N];

inline long long get1(int u){
	return t[u]/(sz[u] + 2);
}

inline long long get2(int u){
	return t[u] - (sz[u] + 1)*get1(u);
}

inline void removeFromGlobal(int i){
	if(!sz[i])return;
	int mnu = chIncome[i].begin()->second;
	globalIncomeSet.erase({income[mnu] + get1(i), mnu});
	int mxu = chIncome[i].rbegin()->second;
	globalIncomeSet.erase({income[mxu] + get1(i), mxu});
}

inline void insertIntoGlobal(int i){
	if(!sz[i])return;
	int mnu = chIncome[i].begin()->second;
	globalIncomeSet.insert({income[mnu] + get1(i), mnu});
	int mxu = chIncome[i].rbegin()->second;
	globalIncomeSet.insert({income[mxu] + get1(i), mxu});
}

inline long long getGlobalMinimum(){
	return globalIncomeSet.begin()->first;
}

inline long long getGlobalMaximum(){
	return globalIncomeSet.rbegin()->first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> f[i];
		adj[f[i]].insert(i);
	}
	for(int i = 1; i <= n; i++){
		sz[i] = (int)adj[i].size();
	}
	for(int i = 1; i <= n; i++){
		income[i] = get2(i);
		for(int u : adj[i]){
			income[i] += get1(u);
		}
		chIncome[f[i]].insert({income[i], i});
	}
	for(int i = 1; i <= n; i++){
		insertIntoGlobal(i);
	}
	int type, i, j;
	while(q--){
		cin >> type;
		if(type == 1){
			cin >> i >> j;
			int u = f[i], v = f[f[i]], w = f[f[f[i]]];
			removeFromGlobal(w);
			removeFromGlobal(v);
			removeFromGlobal(u);
			chIncome[w].erase({income[v], v});
			chIncome[v].erase({income[u], u});
			chIncome[u].erase({income[i], i});
			income[v] -= get1(u);
			income[u] -= get1(i);
			income[u] -= get2(u);
			adj[u].erase(i); sz[u]--;
			income[v] += get1(u);
			income[u] += get2(u);
			chIncome[w].insert({income[v], v});
			chIncome[v].insert({income[u], u});
			insertIntoGlobal(w);
			insertIntoGlobal(v);
			insertIntoGlobal(u);
			
			int x = f[j], y = f[f[j]];
			removeFromGlobal(y);
			removeFromGlobal(x);
			removeFromGlobal(j);
			chIncome[y].erase({income[x], x});
			chIncome[x].erase({income[j], j});
			income[x] -= get1(j);
			income[j] -= get2(j);
			adj[j].insert(i); sz[j]++;
			income[x] += get1(j);
			income[j] += get1(i);
			income[j] += get2(j);
			chIncome[y].insert({income[x], x});
			chIncome[x].insert({income[j], j});
			chIncome[j].insert({income[i], i});
			insertIntoGlobal(y);
			insertIntoGlobal(x);
			insertIntoGlobal(j);

			f[i] = j;
		}else if(type == 2){
			cin >> i;
			cout << income[i] + get1(f[i]) << '\n';
		}else if(type == 3){
			cout << getGlobalMinimum() << " " << getGlobalMaximum() << '\n';
		}
	}

	return 0;
}