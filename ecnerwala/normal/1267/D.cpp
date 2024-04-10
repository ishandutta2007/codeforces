#include<bits/stdc++.h>
using namespace std;

void FAIL() {
	cout << "Impossible" << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		for (int z = 0; z < 3; z++) {
			int v; cin >> v;
			A[i] |= (v << z);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int z = 0; z < 3; z++) {
			int v; cin >> v;
			B[i] |= (v << z);
		}
		B[i] &= A[i];
	}
	//for (int i = 0; i < N; i++) { cerr << i << ' ' << A[i] << ' ' << B[i] << '\n'; }
	vector<bool> CT(N, false);
	vector<bool> vis(N, false);
	vector<int> outVert(8, -1);
	vis[0] = true;
	outVert[7] = 0;
	queue<int> q;
	q.push(7);

	// just link a dummy so we don't try to process them
	outVert[0] = N;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) vis[i] = true;
	}

	vector<pair<int, int>> edges;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			if (A[i] != v) continue;
			vis[i] = true;
			edges.push_back({outVert[A[i]], i});
			if (outVert[B[i]] == -1) {
				CT[i] = true;
				outVert[B[i]] = i;
				q.push(B[i]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			int a = A[i];
			assert(outVert[a] == -1);
			int pc = __builtin_popcount(a);
			assert(pc != 3);
			if (pc == 1) {
				// you're screwed
				FAIL();
			} else if (pc == 2) {
				int x = a & (a-1);
				int y = a - x;
				if (outVert[x] == -1 || outVert[y] == -1) {
					FAIL();
				}
				edges.push_back({outVert[x], i});
				edges.push_back({outVert[y], i});
				vis[i] = true;
				outVert[a] = i;
				CT[i] = false;
				for (int j = 0; j < N; j++) {
					if (vis[j]) continue;
					if (A[j] != a) continue;
					vis[j] = true;
					edges.push_back({i,j});
				}
			} else assert(false);
		}
	}
	cout << "Possible" << '\n';
	for (int i = 0; i < N; i++) {
		cout << int(CT[i]) << " \n"[i+1==N];
	}
	cout << int(edges.size()) << '\n';
	for (auto it : edges) {
		cout << it.first+1 << ' ' << it.second+1 << '\n';
	}

	return 0;
}