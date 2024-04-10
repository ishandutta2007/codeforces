#include<bits/stdc++.h>
using namespace std;

const int MAXV = 5.1e5;
const int V = 5e5;
bool isPrime[MAXV];
void precomp() {
	for (int i = 2; i <= V; i++) isPrime[i] = true;
	for (int p = 2; p <= V; p++) {
		if (!isPrime[p]) continue;
		for (int j = p + p; j <= V; j += p) isPrime[j] = false;
	}
}

vector<pair<int, int>> go(int N) {
	vector<pair<int, int>> edges;
	for (int i = 0; i < N; i++) {
		edges.emplace_back(i, (i+1)%N);
	}
	for (int i = 0; i < N/2 && !isPrime[edges.size()]; i ++) {
		edges.emplace_back(i, i + N/2);
	}
	assert(isPrime[edges.size()]);
	return edges;
}

void test() {
	for (int n = 3; n <= 1000; n++) {
		cerr << n << '\n';
		auto edges = go(n);
		assert(isPrime[edges.size()]);
		for (auto& it : edges) {
			if (it.second < it.first) swap(it.first, it.second);
			assert(it.first != it.second);
		}
		sort(edges.begin(), edges.end());
		assert(unique(edges.begin(), edges.end()) == edges.end());
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	precomp();
	//test();

	int N; cin >> N;
	auto res = go(N);
	cout << res.size() << '\n';
	for (auto it : res) {
		cout << it.first+1 << ' ' << it.second+1 << '\n';
	}

	return 0;
}