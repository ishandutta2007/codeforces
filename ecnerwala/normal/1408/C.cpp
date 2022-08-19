#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; int L; cin >> N >> L;
		vector<int> A(N); for (auto& a : A) cin >> a;
		double tot = 0;
		double x0 = 0; int v0 = 1;
		double x1 = L; int v1 = 1;
		int lo = 0, hi = N-1;
		while (lo <= hi) {
			double t0 = (A[lo] - x0) / v0;
			double t1 = (x1 - A[hi]) / v1;
			if (t0 <= t1) {
				tot += t0;
				x0 = A[lo];
				x1 -= v1 * t0;
				lo++;
				v0++;
			} else {
				tot += t1;
				x1 = A[hi];
				x0 += v0 * t1;
				hi--;
				v1++;
			}
		}
		tot += (x1 - x0) / (v0 + v1);
		cout << fixed << setprecision(15) << tot << '\n';
	}

	return 0;
}