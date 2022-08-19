#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N;
vector<int> adj[MAXN];
unordered_set<int> X;
unordered_set<int> Y;

std::istream& operator >> (std::istream& i, unordered_set<int>& s) {
	int sz; i >> sz;
	for (int z = 0; z < sz; z++) {
		int v; cin >> v;
		s.insert(v);
	}
	return i;
}

int dfs(int cur, int prv = 0) {
	if (X.count(cur)) return cur;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		int cnd = dfs(nxt, cur);
		if (cnd) return cnd;
	}
	return 0;
}

void go() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> X >> Y;
	assert(!X.empty());
	assert(!Y.empty());
	int bRt = *Y.begin();
	cout << "B" << ' ' << bRt << endl;
	int aRt; cin >> aRt;
	int top = dfs(aRt);
	assert(X.count(top));
	cout << "A" << ' ' << top << endl;
	int btop; cin >> btop;
	if (Y.count(btop)) {
		cout << "C" << ' ' << top << endl;
	} else {
		cout << "C" << ' ' << -1 << endl;
	}

	for (int i = 1; i <= N; i++) {
		adj[i].clear();
	}
	X.clear();
	Y.clear();
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T --> 0) {
		go();
	}

	return 0;
}