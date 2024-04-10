#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXK 100000

int N, K, M;
int ans;
int advantage = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> M;
		ans += M - 1;
		int first, curr;
		cin >> first;
		if (first == 1) {
			bool good = true;
			for (int j = 1; j < M; j++) {
				cin >> curr;
				if (curr != first + 1) {
					good = false;
				}
				first = curr;
				if (good) {
					advantage += 2;
				}
			}
		}
		else {
			for (int j = 1; j < M; j++) {
				cin >> curr;
			}
		}
	}

	ans += N - 1;
	ans -= advantage;

	cout << ans << endl;
	return 0;
}