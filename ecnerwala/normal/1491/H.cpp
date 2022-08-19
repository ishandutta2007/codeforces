#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	const int B = 400;
	vector<int> A(N);
	for (int i = 1; i < N; i++) {
		cin >> A[i]; A[i]--;
	}
	vector<int> bucket_prv(N);
	for (int i = 1; i < N; i++) {
		if (A[i] / B == i / B) bucket_prv[i] = bucket_prv[A[i]];
		else bucket_prv[i] = A[i];
	}
	vector<int> bucket_lazy((N-1)/B+1, 0);
	auto get_par = [&](int a) {
		int lz = bucket_lazy[a / B];
		return max(A[a] - lz, 0);
	};
	auto compute_bucket = [&](int mid) {
		if (bucket_lazy[mid] < B) {
			int lo = max(mid * B, 1);
			int hi = min((mid+1) * B, N);
			int lz = bucket_lazy[mid];
			for (int i = lo; i < hi; i++) {
				int a = max(A[i] - lz, 0);
				if (a / B == i / B) bucket_prv[i] = bucket_prv[a];
				else bucket_prv[i] = a;
			}
		}
	};
	auto get_bucket_par = [&](int a) {
		int lz = bucket_lazy[a / B];
		if (lz < B) {
			return bucket_prv[a];
		} else {
			return max(A[a] - lz, 0);
		}
	};
	while (Q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x; cin >> l >> r >> x; l--, r--; // inclusive interval
			if (l / B == r / B) {
				for (int i = l; i <= r; i++) {
					A[i] = max(A[i] - x, 0);
				}
				compute_bucket(l / B);
			} else {
				for (int i = l; i < (l / B + 1) * B; i++) {
					A[i] = max(A[i] - x, 0);
				}
				compute_bucket(l / B);
				for (int mid = l / B + 1; mid <= r / B - 1; mid++) {
					bucket_lazy[mid] = min(bucket_lazy[mid] + x, max(B+1, N+1));
					compute_bucket(mid);
				}
				for (int i = r / B * B; i <= r; i++) {
					A[i] = max(A[i] - x, 0);
				}
				compute_bucket(r / B);
			}
		} else if (t == 2) {
			int u, v; cin >> u >> v; u--, v--;
			while (true) {
				if (u > v) swap(u, v);
				if (v / B > u / B) {
					v = get_bucket_par(v);
					continue;
				}
				int pu = get_bucket_par(u);
				int pv = get_bucket_par(v);
				if (pu != pv) {
					u = pu;
					v = pv;
					continue;
				}
				break;
			}
			while (u != v) {
				if (u > v) swap(u, v);
				v = get_par(v);
			}
			cout << u+1 << '\n';
		}
	}

	return 0;
}