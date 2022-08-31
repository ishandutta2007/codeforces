#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5.1e5;
const int N = 5e5;
int A[MAXN];

const int B = 700;
const int MAXB = B + 20;
int ans[MAXB][MAXB];

const int MAXQ = 5.1e5;
int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Q;
	while (Q--) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			A[x] += y;
			for (int m = 1; m <= B; m++) {
				ans[m][x%m] += y;
			}
		} else if (t == 2) {
			if (x <= B) {
				cout << ans[x][y] << '\n';
			} else {
				int s = 0;
				for (int v = y; v <= N; v += x) {
					s += A[v];
				}
				cout << s << '\n';
			}
		} else assert(false);
	}

	return 0;
}