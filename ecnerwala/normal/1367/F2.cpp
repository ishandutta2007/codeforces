#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i].first; A[i].second = i;
		}
		sort(A.begin(), A.end());

		//for (int i = 0; i < N; i++) { cerr << A[i].second << ' '; } cerr << '\n';
		int best = 1;
		int cur = 1;
		for (int i = 1; i < N; i++) {
			if (A[i].second > A[i-1].second) {
				cur++;
			} else {
				assert(A[i].first > A[i-1].first);
				// Long string ending with i
				for (int j = i; j < N && A[j].first == A[i].first; j++) {
					if (A[j].second > A[i-1].second) cur++;
				}
				best = max(best, cur);

				// Just the two of these guys
				{
					int x = i-1; while (x >= 0 && A[x].first == A[i-1].first) x--;
					x++;
					int y = i; while (y < N && A[y].first == A[i].first) y++;
					y--;
					// [x, i-1] and [i, y]
					for (int a = x, b = i; a <= i-1 && b <= y; ) {
						if (A[a].second < A[b].second) {
							best = max(best, (a-x)+1 + (y-b)+1);
							a++;
						} else {
							b++;
						}
					}
				}

				// Long string starting with i-1
				cur = 1;
				for (int j = i-1; j >= 0 && A[j].first == A[i-1].first; j--) {
					if (A[j].second < A[i].second) cur++;
				}
			}
			best = max(best, cur);
		}
		cout << N - best << '\n';
	}

	return 0;
}