#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = MAXN * MAXN;
const int MAXQ = 2e3;

const int MAXV = 2 * MAXN;

int N, M, Q;

pair<int, bool> par[MAXV];
pair<int, bool> get_par(int a) {
	if(par[a].first == a) return par[a];
	auto t = get_par(par[a].first);
	return par[a] = pair<int, bool>(t.first, t.second ^ par[a].second);
}
bool merge(int a, int b) {
	auto pa = get_par(a), pb = get_par(b);
	if(pa.first == pb.first) return pa.second != pb.second;
	par[pa.first] = pair<int, bool>(pb.first, pa.second ^ pb.second ^ 1);
	return true;
}

pair<int, int> R[MAXQ];
int res[MAXQ];

pair<pair<int, int>, pair<int, int>> edges[MAXM];

int query(int l, int r) {
	for(int i = 1; i <= N; i++) {
		par[i] = make_pair(i, false);
	}
	for(int z = 0; z < M; z++) {
		auto e = edges[z];
		int w = e.first.first;
		int i = e.first.second;
		int u = e.second.first;
		int v = e.second.second;
		if(l <= i && i <= r) {
			if(!merge(u, v)) {
				return w;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 1; i <= M; i++) {
		int u, v;
		int w;
		scanf("%d %d %d", &u, &v, &w);
		edges[i - 1] = make_pair(make_pair(w, i), make_pair(u, v));
	}
	sort(edges, edges + M);
	reverse(edges, edges + M);

	for(int i = 1; i <= Q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d ", query(l, r));
	}
	printf("\n");
	return 0;
}