#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int T;
int N, K;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		int best = 1123456789, pos = -1;
		for (int i = 0; i < N - K; i++) {
			int dist = (A[i + K] - A[i] + 1) / 2;
			if (dist < best) {
				best = dist;
				pos = A[i] + dist;
			}
		}
		cout << pos << '\n';
	}

	cout.flush();
	return 0;
}