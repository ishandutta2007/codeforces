#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N);
	for (auto& a : A) cin >> a, a--;

	int new_root = -1;
	int ans = 0;
	int epoch = 2;
	vector<int> vis(N);
	for (int i = 0; i < N; i++) {
		if (A[i] == i) {
			new_root = i;
			vis[i] = 1;
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		epoch++;
		int cur = i;
		while (vis[cur] == 0) {
			vis[cur] = epoch;
			cur = A[cur];
		}
		if (vis[cur] == epoch) {
			ans++;
			if (new_root == -1) {
				new_root = cur;
			}
			A[cur] = new_root;
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < N; i++) {
		cout << A[i]+1 << " \n"[i+1==N];
	}

	return 0;
}