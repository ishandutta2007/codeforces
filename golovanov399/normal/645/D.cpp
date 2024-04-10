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

void panic(){
	puts("-1");
	exit(0);
}

int main(){

	vector<pair<int, int>> qw;

	int n = nxt(), m = nxt();
	vector<vector<itn>> a(n), b(n);
	for (int i = 0; i < m; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		b[v].push_back(u);

		qw.push_back({u, v});
	}

	set<pair<int, int>> S;

	vector<int> deg(n);
	for (int i = 0; i < n; i++){
		deg[i] = a[i].size();
		S.insert(make_pair(deg[i], i));
	}

	vector<int> order;
	for (int _ = 0; _ < n - 1; _++){
		auto p = *S.begin();
		S.erase(S.begin());
		if (p.first > 0)
			panic();
		order.push_back(p.second);
		if (S.begin()->first == 0){
			panic();
		}

		int v = p.second;
		for (auto x : b[v]){
			S.erase(make_pair(deg[x], x));
			deg[x]--;
			S.insert(make_pair(deg[x], x));
		}
	}

	order.push_back(S.begin()->second);
	set<pair<int, int>> al;
	reverse(all(order));
	for (int i = 0; i < n - 1; i++){
		al.insert(make_pair(order[i], order[i + 1]));
	}

	for (int i = 0; i < m; i++){
		if (al.empty()){
			cout << i << "\n";
			return 0;
		}
		auto it = al.find(qw[i]);
		if (it != al.end())
			al.erase(it);
	}
	cout << m << "\n";

	return 0;
}