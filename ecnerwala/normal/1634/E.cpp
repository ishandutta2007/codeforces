#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int M; cin >> M;
	std::vector<std::vector<int>> A(M);

	int V = 0;
	for (int i = 0; i < M; i++) {
		int N; cin >> N;
		A[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		V += N;
	}

	std::vector<int> match(V);
	{
		std::map<int, int> last_idx;
		int idx = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < int(A[i].size()); j++) {
				int cur = idx++;
				auto it = last_idx.find(A[i][j]);
				if (it == last_idx.end()) {
					last_idx[A[i][j]] = cur;
				} else {
					int nxt = it->second;
					last_idx.erase(it);

					match[cur] = nxt;
					match[nxt] = cur;
				}
			}
		}
		if (!last_idx.empty()) {
			cout << "NO" << '\n';
			exit(0);
		}
	}

	std::vector<bool> vis(V);
	std::vector<bool> S(V);
	for (int st = 0; st < V; st++) {
		if (vis[st]) continue;
		int cur = st;
		do {
			vis[cur] = true;
			S[cur] = false;
			cur ^= 1;
			vis[cur] = true;
			S[cur] = true;
			cur = match[cur];
		} while (cur != st);
	}

	cout << "YES" << '\n';
	for (int i = 0, idx = 0; i < M; i++) {
		for (int j = 0; j < int(A[i].size()); j++) {
			cout << (S[idx++] ? 'L' : 'R');
		}
		cout << '\n';
	}

	return 0;
}