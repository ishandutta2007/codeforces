#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;

	vector<vector<bool>> adj(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N/4; j++) {
			char c = s[j];
			int v = ('0' <= c && c <= '9') ? (c - '0') : (10 + (c - 'A'));
			for (int z = 0; z < 4; z++) {
				adj[i][4*j+z] = v & (1 << (3-z));
			}
		}
	}

	const int64_t UNREACHABLE = 614 * N;

	vector<int> outDeg(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			outDeg[i] += adj[i][j];
		}
	}

	int pivot = int(min_element(outDeg.begin(), outDeg.end()) - outDeg.begin());

	vector<int> inds(N); iota(inds.begin(), inds.end(), 0);
	sort(inds.begin(), inds.end(), [&](int a, int b) -> bool { return adj[adj[pivot][a] != adj[pivot][b] ? pivot : a][b]; });

	vector<int> cyc(N);
	for (int i = 0; i < N; i++) {
		cyc[i] = outDeg[inds[i]];
	}

	int64_t ans = 0;

	reverse(cyc.begin(), cyc.end());
	while (N && cyc[N-1] == N-1) {
		ans += (UNREACHABLE + 1) * (N-1);
		N--; cyc.pop_back();
	}
	reverse(cyc.begin(), cyc.end());

	for (int i = 0; i < N; i++) {
		ans += 3 * (N-1) - 2 * cyc[i] - cyc[(i+cyc[i])%N];
	}

	cout << ans << '\n';

	return 0;
}