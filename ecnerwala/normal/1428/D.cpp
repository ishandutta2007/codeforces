#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;

	vector<pair<int, int>> targets; targets.reserve(2*N);

	int R3 = -1;
	int C3 = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] == 3) {
			if (R3 >= 0) {
				targets.push_back({R3, i});
			}
			R3++;
			targets.push_back({R3, i});
			C3 = i;
		}
	}

	if (C3 != -1) {
		for (int i = N-1; i > C3; i--) {
			if (A[i] == 2) {
				targets.push_back({R3, i});
				C3 = -1;
				break;
			}
		}
	}

	int R = N;
	vector<int> stk;
	for (int i = 0; i < N; i++) {
		if (A[i] == 2) {
			stk.push_back(i);
		} else if (A[i] == 1) {
			R--;
			if (!stk.empty()) {
				targets.push_back({R, stk.back()});
				stk.pop_back();
			} else if (C3 != -1 && i > C3) {
				targets.push_back({R3, i});
				C3 = -1;
			}
			targets.push_back({R, i});
		}
	}
	if (!stk.empty()) {
		cout << -1 << '\n';
		exit(0);
	}
	if (C3 != -1) {
		cout << -1 << '\n';
		exit(0);
	}

	cout << int(targets.size()) << '\n';
	for (auto [r, c] : targets) {
		cout << r+1 << ' ' << c+1 << '\n';
	}

	return 0;
}