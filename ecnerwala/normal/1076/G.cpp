#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
const int MAXM = 8;
int N, M;
long long A[MAXN];

struct trans {
	int8_t nxt[MAXM];
	friend trans operator * (const trans& a, const trans& b) {
		trans res;
		for (int i = 0; i <= M; i++) {
			res.nxt[i] = a.nxt[b.nxt[i]];
		}
		return res;
	}
};

struct node {
	bool flip;
	trans tr[2];

	const trans& operator [] (int i) const {
		return tr[i^flip];
	}
	void update(const node& c0, const node& c1) {
		tr[0] = c0[0] * c1[0];
		tr[1] = c0[1] * c1[1];
	}
};

const int S = (1 << 18);
node seg[2*S];

void init() {
	trans evens;
	for (int i = 0; i < M; i++) {
		evens.nxt[i] = int8_t(i+1);
	}
	evens.nxt[M] = int8_t(M);
	trans odds;
	for (int i = 0; i < M; i++) {
		odds.nxt[i] = int8_t(i+1);
	}
	odds.nxt[M] = int8_t(0);

	for (int i = 2*S-1; i >= S; i--) {
		seg[i].flip = (i-S < N ? (A[i-S]&1) : false);
		seg[i].tr[0] = evens;
		seg[i].tr[1] = odds;
	}
	for (int i = S-1; i; i--) {
		seg[i].flip = false;
		seg[i].update(seg[2*i], seg[2*i+1]);
	}
}

void doFlip(int l, int r, int i = 1, int st = 0, int en = S) {
	assert(st <= l && l <= r && r <= en);
	if (l == r) return;
	if (st == l && r == en) {
		seg[i].flip ^= 1;
		return;
	}
	assert(i < S);
	int md = (st + en) / 2;
	if (l < md) {
		doFlip(l, min(r, md), 2*i+0, st, md);
	}
	if (r > md) {
		doFlip(max(l, md), r, 2*i+1, md, en);
	}
	seg[i].update(seg[2*i], seg[2*i+1]);
}

int query(int l, int r, int v, bool flip = 0, int i = 1, int st = 0, int en = S) {
	assert(st <= l && l <= r && r <= en);
	if (l == r) return v;
	if (st == l && r == en) {
		return seg[i][flip].nxt[v];
	}
	assert(i < S);
	flip ^= seg[i].flip;
	int md = (st + en) / 2;
	if (r > md) {
		v = query(max(l, md), r, v, flip, 2*i+1, md, en);
	}
	if (l < md) {
		v = query(l, min(r, md), v, flip, 2*i+0, st, md);
	}
	return v;
}

int Q;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) cin >> A[i];

	init();

	for (int q = 0; q < Q; q++) {
		int t; cin >> t;
		if (t == 1) {
			int l, r; cin >> l >> r;
			l--;
			long long d; cin >> d;
			if (d & 1) {
				// do stuff
				doFlip(l, r);
			}
		} else if (t == 2) {
			int l, r; cin >> l >> r;
			l--;
			if (query(l, r, M) == 0) {
				// it's a winning position for the player who reached this square
				cout << 2 << '\n';
			} else {
				cout << 1 << '\n';
			}
		} else assert(false);
	}

	return 0;
}