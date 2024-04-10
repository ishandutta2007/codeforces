#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a, a--;
		int resp = [&]() -> int {
			int lo = 0, hi = N;
			while (lo < hi && A[lo] == lo) lo++;
			while (lo < hi && A[hi-1] == hi-1) --hi;

			if (lo == hi) return 0;

			bool has_fixed_pt = false;
			for (int i = lo; i < hi; i++) {
				if (A[i] == i) has_fixed_pt = true;
			}

			if (!has_fixed_pt) {
				return 1;
			}
			return 2;
		}();
		cout << resp << '\n';
	}

	return 0;
}