#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
template <typename T> T max(const T& a, const T& b, const T& c) { return max(max(a,b), c); }
template <typename T> T max(const T& a, const T& b, const T& c, const T& d) { return max(max(a,b,c), d); }

struct seg {
	int sum = 0;

	int bestD = 0;
	int bestM = 0;
	int bestD1M = 0;
	int bestMD2 = 0;
	int bestD1MD2 = 0;

	seg() { }

	explicit seg (int d) {
		assert(d == 1 || d == -1);
		sum = d;
		bestD = max(0, sum);
		bestM = max(-2 * 0, -2 * sum);
		bestD1M = max(0 - 2 * 0, 0 - 2 * sum, sum - 2 * sum);
		bestMD2 = max(- 2 * 0 + 0, -2 * 0 + sum, -2 * sum + sum);
		bestD1MD2 = max(0 - 2 * 0 + 0, 0 - 2 * 0 + sum, 0 - 2 * sum + sum, sum - 2 * sum + sum);
	}

	void shift(int d) {
		sum += d;
		bestD += d;
		bestM += -2 * d;
		bestD1M += -1 * d;
		bestMD2 += -1 * d;
		bestD1MD2 += 0 * d;
	}

	seg(const seg& a, const seg& b_) {
		seg b = b_; b.shift(a.sum);
		sum = b.sum;
		bestD = max(a.bestD, b.bestD);
		bestM = max(a.bestM, b.bestM);

		bestD1M = max(a.bestD1M, b.bestD1M, a.bestD + b.bestM);
		bestMD2 = max(a.bestMD2, b.bestMD2, a.bestM + b.bestD);

		bestD1MD2 = max(a.bestD1MD2, b.bestD1MD2, a.bestD + b.bestMD2, a.bestD1M + b.bestD);
	}
};

const int S = 1 << 18;
seg seg_tree[2 * S];

const int MAXN = int(1.1e5) * 2;
int N;
char A[MAXN];

int Q;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	N = 2 * (N-1);
	cin >> A;

	for (int i = 0; i < N; i++) {
		seg_tree[i + S] = seg(A[i] == '(' ? 1 : -1);
	}
	for (int i = S-1; i; i--) {
		seg_tree[i] = seg(seg_tree[2*i], seg_tree[2*i+1]);
	}

	assert(seg_tree[1].sum == 0);
	assert(seg_tree[1].bestM == 0);
	cout << seg_tree[1].bestD1MD2 << '\n';
	for (int q = 0; q < Q; q++) {
		int i, j; cin >> i >> j; i--, j--;
		swap(A[i], A[j]);
		seg_tree[i+S] = seg(A[i] == '(' ? 1 : -1);
		seg_tree[j+S] = seg(A[j] == '(' ? 1 : -1);
		for (int a = (i+S)/2, b = (j+S)/2; a && b; a/=2, b/=2) {
			seg_tree[a] = seg(seg_tree[2*a], seg_tree[2*a+1]);
			seg_tree[b] = seg(seg_tree[2*b], seg_tree[2*b+1]);
		}
		assert(seg_tree[1].sum == 0);
		assert(seg_tree[1].bestM == 0);
		cout << seg_tree[1].bestD1MD2 << '\n';
	}

	return 0;
}