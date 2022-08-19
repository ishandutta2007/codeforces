#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	vector<int> leftmost(N); iota(leftmost.begin(), leftmost.end(), 0);
	struct vert_dat {
		pair<int, int> prv_pred;
		pair<int, int> prv_succ;
		pair<int, int> nxt_pred;
		pair<int, int> nxt_succ;
	};
	vector<vert_dat> verts(N);
	for (int i = 0; i < N; i++) {
		verts[i].prv_pred = {-1, -1};
		verts[i].prv_succ = {N, -1};
		verts[i].nxt_pred = {-1, -1};
		verts[i].nxt_succ = {N, -1};
	}

	int ans = 0;
	for (int q = 0; q < Q; q++) {
		int L, R; cin >> L >> R; L--;
		int b = R;
		while (leftmost[b-1] > L) b--;
		for (; b < R; b++) {
			assert(b > L && leftmost[b-1] <= L);
			while (leftmost[b] > L) {
				leftmost[b]--;
				int a = leftmost[b];
				// insert the a-b constraint
				if (A[a] < A[b] && A[b] < verts[a].nxt_succ.first) {
					if (verts[a].nxt_succ.second != -1) {
						int c = verts[a].nxt_succ.second;
						verts[c].prv_pred.second = -1;
						ans--;
					}
					verts[a].nxt_succ = {A[b], b};
					if (verts[b].prv_pred.second != -1) {
						int c = verts[b].prv_pred.second;
						verts[c].nxt_succ.second = -1;
						ans--;
					}
					verts[b].prv_pred = {A[a], a};
					ans++;
				} else if (A[a] > A[b] && A[b] > verts[a].nxt_pred.first) {
					if (verts[a].nxt_pred.second != -1) {
						int c = verts[a].nxt_pred.second;
						verts[c].prv_succ.second = -1;
						ans--;
					}
					if (verts[b].prv_succ.second != -1) {
						int c = verts[b].prv_succ.second;
						verts[c].nxt_pred.second = -1;
						ans--;
					}
					verts[a].nxt_pred = {A[b], b};
					verts[b].prv_succ = {A[a], a};
					ans++;
				} else {
					continue;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}