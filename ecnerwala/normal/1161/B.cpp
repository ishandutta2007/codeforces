#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<pair<int, int>> edges;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--, b--;
		if (a > b) swap(a, b);
		edges.emplace_back(a, b);
	}
	sort(edges.begin(), edges.end());

	vector<int> primeFacs;
	for (int p = 2, v = N; p <= v; p++) {
		if (v % p == 0) {
			primeFacs.push_back(p);
			while (v % p == 0) v /= p;
		}
	}

	for (int p : primeFacs) {
		int k = N / p;
		vector<pair<int, int>> nEdges;
		for (auto it : edges) {
			it.first += k, it.first %= N;
			it.second += k, it.second %= N;
			if (it.first > it.second) swap(it.first, it.second);
			nEdges.push_back(it);
		}
		sort(nEdges.begin(), nEdges.end());
		if (nEdges == edges) {
			cout << "Yes" << '\n';
			exit(0);
		}
	}
	cout << "No" << '\n';
	exit(0);

	return 0;
}