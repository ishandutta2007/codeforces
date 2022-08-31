#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5.1e5;
const int MAXQ = 5.1e5;

const int S = 1<<19;
struct seg_node {
	int maxVal;
	int maxVal2;
	int lazyAdd;
	int lazyMax;
	int lazyCnt;
} seg[2*S];

int N, Q;
int A[MAXN];
int start[MAXN];

const int MAXV = 1.1e6;
vector<pair<pair<int, int>, int>> evts[MAXV];

void propogate(int i) {
	if (i >= S) {
		// do nothing
	} else {
		if (seg[i].lazyAdd) {
			for (int z = 0; z < 2; z++) {
				int j = 2*i+z;
				if (seg[i].maxVal <= seg[j].maxVal) {
					if (seg[i].lazyMax + seg[j].lazyAdd > seg[j].lazyMax) {
						seg[j].lazyMax = seg[i].lazyMax + seg[j].lazyAdd;
						seg[j].lazyCnt = 0;
					}
					if (seg[i].lazyMax + seg[j].lazyAdd == seg[j].lazyMax) {
						seg[j].lazyCnt += seg[i].lazyCnt;
					}

					seg[j].maxVal = seg[i].maxVal;
					seg[j].lazyAdd += seg[i].lazyAdd;
				} else {
					assert(seg[i].maxVal2 >= seg[j].maxVal);
					seg[j].lazyAdd += seg[i].lazyAdd;

					if (seg[j].maxVal+seg[j].lazyAdd > seg[j].lazyMax) {
						seg[j].lazyMax = seg[j].maxVal+seg[j].lazyAdd;
						seg[j].lazyCnt = 0;
					}
					if (seg[j].maxVal+seg[j].lazyAdd == seg[j].lazyMax) {
						seg[j].lazyCnt++;
					}
				}
			}
			seg[i].lazyCnt = 0;
			seg[i].lazyAdd = 0;
			seg[i].lazyMax = seg[i].maxVal;
		}
	}
}

void update(int i) {
	assert(i < S);
	assert(seg[i].lazyCnt == 0);
	assert(seg[i].lazyAdd == 0);
	auto& n = seg[i];
	auto& l = seg[2*i];
	auto& r = seg[2*i+1];
	if (l.maxVal > r.maxVal) {
		n.maxVal = l.maxVal;
		n.maxVal2 = max(r.maxVal, l.maxVal2);
	} else if (r.maxVal > l.maxVal) {
		n.maxVal = r.maxVal;
		n.maxVal2 = max(l.maxVal, r.maxVal2);
	} else {
		n.maxVal = l.maxVal;
		n.maxVal2 = max(l.maxVal2, r.maxVal2);
	}
	assert(n.maxVal > n.maxVal2);
	seg[i].lazyMax = seg[i].maxVal;
}

void insert(int i, int l, int r, int ql, int qr, int val) {
	if (r <= ql || l >= qr) return;

	if (ql <= l && r <= qr) {
		assert(seg[i].maxVal2 < seg[i].maxVal);
		assert(val != seg[i].maxVal2);
		assert(val != seg[i].maxVal);
		if (val < seg[i].maxVal2) {
			// we need to propogate the insert

			assert(i < S);

			propogate(i);
			int m = (l+r)/2;
			insert(2*i, l, m, ql, qr, val);
			insert(2*i+1, m, r, ql, qr, val);
			update(i);
		} else {
			seg[i].maxVal = min(seg[i].maxVal, val);
			seg[i].lazyAdd++;
			if (seg[i].maxVal + seg[i].lazyAdd > seg[i].lazyMax) {
				seg[i].lazyMax = seg[i].maxVal + seg[i].lazyAdd;
				seg[i].lazyCnt = 0;
			}
			if (seg[i].maxVal + seg[i].lazyAdd == seg[i].lazyMax) {
				seg[i].lazyCnt++;
			}
		}
	} else {
		assert(i < S);
		propogate(i);
		int m = (l+r)/2;
		insert(2*i, l, m, ql, qr, val);
		insert(2*i+1, m, r, ql, qr, val);
		update(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		start[i] = 0;
	}

	for (int q = 1; q <= Q; q++) {
		int pos, a; cin >> pos >> a; pos--;
		evts[A[pos]].push_back({{start[pos], q}, pos});
		A[pos] = a;
		start[pos] = q;
	}
	for (int i = 0; i < N; i++) {
		evts[A[i]].push_back({{start[i], Q+1}, i});
	}

	for (int i = 2*S-1; i > 0; i--) {
		seg[i].maxVal = N;
		seg[i].maxVal2 = -1;
		seg[i].lazyAdd = 0;
		seg[i].lazyMax = N;
		seg[i].lazyCnt = 0;
	}

	for (int v = 0; v < MAXV; v++) {
		for (auto evt : evts[v]) {
			int l = evt.first.first, r = evt.first.second;
			int pos = evt.second;
			insert(1, 0, S, l, r, pos);
		}
	}

	for (int i = 1; i < S; i++) propogate(i);

	for (int q = 1; q <= Q; q++) {
		assert(seg[S+q].lazyAdd == N);
		assert(seg[S+q].lazyMax == N);
		cout << seg[S+q].lazyCnt << '\n';
	}

	return 0;
}