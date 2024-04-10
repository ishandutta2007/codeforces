#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
const int MAXM = 3.1e5;
int N, M;
int A[MAXN];
int B[MAXM];

const int S = 1 << 20;
struct {
	int val = 0;
	int maxSuff = 0;
} seg[2 * S];

void update(int v, int d) {
	for (int a = v + S; a; a /= 2) {
		seg[a].val += d;
		seg[a].maxSuff = (a >= S ? max(seg[a].val, 0) : max(seg[2*a+0].maxSuff + seg[2*a+1].val, seg[2*a+1].maxSuff));
	}
}

int query() {
	if (seg[1].maxSuff <= 0) {
		return -1;
	}
	int val = 0;
	int a;
	for (a = 1; a < S; ) {
		if (seg[2 * a + 1].maxSuff + val > 0) {
			a = 2 * a + 1;
		} else {
			val += seg[2 * a + 1].val;
			assert(seg[2 * a + 0].maxSuff + val > 0);
			a = 2 * a + 0;
		}
	}
	return a - S;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		update(A[i], +1);
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		update(B[i], -1);
	}

	int Q; cin >> Q;
	for (int q = 0; q < Q; q++) {
		int t, i, x; cin >> t >> i >> x;
		i--;
		if (t == 1) {
			update(A[i], -1);
			A[i] = x;
			update(A[i], +1);
		} else if (t == 2) {
			update(B[i], +1);
			B[i] = x;
			update(B[i], -1);
		} else assert(false);
		cout << query() << '\n';
	}

	return 0;
}