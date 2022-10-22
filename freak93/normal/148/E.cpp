#include <iostream>
#include <vector>

using namespace std;

inline int max(const int &a, const int &b) {
	if (a < b)
		return b;
	return a;
}

int main() {
	int N, M; cin >> N >> M;

	vector<int> best(M + 1, -1000000000);
	best[0] = 0;
	for (int i = 0; i < N; ++i) {
		int K; cin >> K;

		vector<int> a(K + 1), left(K + 1, 0);
		for (int j = 1; j <= K; ++j) {
			cin >> a[j];
			left[j] = left[j - 1] + a[j];
		}

		vector<int> right(K + 2, 0);
		for (int j = K; j > 0; --j) {
			right[j] = right[j + 1] + a[j];
		}
		vector<int> local(K + 1, 0);
		for (int j = 1; j <= K; ++j)
			for (int k = 0; k <= j; ++k)
				local[j] = max(local[j], left[k] + right[K - j + k + 1]);
		
		for (int j = M; j > 0; --j)
			for (int k = 1; k <= K && k <= j; ++k)
				best[j] = max(best[j], best[j - k] + local[k]);
	}

	cout << best[M];
}