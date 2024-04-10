#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Zalupa {
	int n;
	vector<pair<int, int>> par;
	vector<int> rank;

	Zalupa(int n = 0):n(n){
		par.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++){
			par[i] = {i, 0};
		}
	}

	pair<int, int> get(int v){
		if (v != par[v].first){
			int prt = par[v].second;
			par[v] = get(par[v].first);
			par[v].second ^= prt;
		}
		return par[v];
	}

	bool connect(int u, int v){
		auto pa = get(u);
		u = pa.first;
		int x = pa.second;
		auto pb = get(v);
		v = pb.first;
		int y = pb.second;
		if (u == v){
			return x != y;
		} else {
			if (rank[u] < rank[v]){
				swap(u, v);
			}
			par[v] = {u, x ^ y ^ 1};
			if (rank[u] == rank[v])
				++rank[u];
			return true;
		}
	}
};

int main(){

	int n = nxt(), m = nxt(), q = nxt();
	vector<pair<int, pair<int, pair<int, int>>>> ed(m);
	for (int i = 0; i < m; i++){
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		ed[i] = {-w, {i, {u, v}}};
	}				// m

	sort(all(ed));

	vector<int> ans(q, -1);
	vector<int> l(q), r(q);
	for (int i = 0; i < q; i++){
		l[i] = nxt() - 1, r[i] = nxt() - 1;
	}				// q

	vector<int> ev;
	for (int i = 0; i < q; i++){
		ev.push_back(l[i]);
		ev.push_back(r[i] + 1);
	}
	sort(all(ev));
	ev.resize(unique(all(ev)) - ev.begin());
	vector<int> num(m + 1);
	for (int i : ev)
		num[i] = 1;
	for (int i = 1; i <= m; i++)
		num[i] += num[i - 1];
	vector<vector<int>> zlp(ev.size() + 1);
	for (int i = 0; i < q; i++){
		for (int j = num[l[i]]; j < num[r[i] + 1]; j++){
			zlp[j].push_back(i);
		}
	}

	// for (auto p = ed.begin(); p != ed.end(); ++p){
	// 	int i = p->second.first;
	// 	int u = p->second.second.first, v = p->second.second.second;
	// 	// for (int j = 0; j < q; j++){
	// 	for (int j : zlp[num[i]]){
	// 		if (ans[j] > -1)
	// 			continue;
	// 		if (!dsu[j].connect(u, v)){
	// 			ans[j] = -p->first;
	// 		}
	// 	}
	// }				// m * q + q * n * log(n)

	for (int i = 0; i < q; i++){
		Zalupa dsu(n);
		bool ok = true;
		for (const auto& p : ed){
			int j = p.second.first;
			if (j < l[i] || j > r[i])
				continue;
			int u = p.second.second.first;
			int v = p.second.second.second;
			if (!dsu.connect(u, v)){
				printf("%d\n", -p.first);
				ok = false;
				break;
			}
		}
		if (ok)
			puts("-1");
	}

	// for (auto x : ans){
	// 	printf("%d\n", x);
	// }

	return 0;
}