#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int deg[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	int S;
	cin >> N >> S;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		deg[u] ++;
		deg[v] ++;
	}
	int leafs = 0;
	for (int i = 1; i <= N; i++) {
		leafs += (deg[i] == 1);
	}
	cout << fixed << setprecision(20) << (double(S) / leafs) * 2 << '\n';

	return 0;
}