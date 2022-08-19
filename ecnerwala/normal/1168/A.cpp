#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int M;
int A[MAXN];

bool is_good(int v) {
	assert(v < M);
	int cur = 0;
	for (int i = 0; i < N; i++) {
		// A[i] .. A[i] + v, inclusive
		int lo = A[i];
		int hi = A[i] + v;
		if (hi >= M) {
			if (hi - M >= cur) {
				// cur doesn't change
				continue;
			} else {
				hi = M-1;
			}
		}
		if (hi >= cur) {
			cur = max(cur, lo);
			continue;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int mi = -1, ma = M;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (is_good(md)) {
			ma = md;
		} else {
			mi = md;
		}
	}
	cout << ma << '\n';

	return 0;
}