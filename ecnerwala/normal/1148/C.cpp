#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int P[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	vector<pair<int, int>> swaps;
	auto do_swap = [&] (int a, int b) {
		assert(abs(a - b) >= N/2);
		swaps.emplace_back(a, b);
		swap(P[a], P[b]);
	};
	for (int i = 1; i <= N; i++) {
		while (P[i] != i) {
			int j = P[i];
			assert(i < j);
			if (j - i >= N/2) {
				do_swap(i, j);
			} else if (j <= N/2) {
				do_swap(i, N);
				do_swap(j, N);
				do_swap(i, N);
			} else if (i > N/2) {
				do_swap(i, 1);
				do_swap(j, 1);
				do_swap(i, 1);
			} else {
				do_swap(i, N);
				do_swap(j, 1);
				do_swap(1, N);
				do_swap(i, N);
				do_swap(j, 1);
			}
		}
	}

	cout << swaps.size() << '\n';
	for (auto it : swaps) {
		cout << it.first << ' ' << it.second << '\n';
	}

	return 0;
}