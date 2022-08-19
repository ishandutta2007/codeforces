#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	auto is_good = [&](int v) -> bool {
		for (int z = 0; z < 2; z++) {
			int j = 0;
			for (int i = 0; i < N; i++) {
				if (((j & 1) == z) || A[i] <= v) {
					j++;
				}
			}
			if (j >= K) return true;
		}
		return false;
	};

	int ma = *max_element(A.begin(), A.end())+1;
	int mi = *min_element(A.begin(), A.end())-1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (is_good(md)) ma = md;
		else mi = md;
	}
	cout << ma << '\n';

	return 0;
}