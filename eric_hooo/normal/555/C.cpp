#include <bits/stdc++.h>
using namespace std;

vector <int> all;
int X[200010], Y[200010]; char OP[200010];
int N;

void chmax(int &x, int y) {
	x = max(x, y);
}

struct Segment_tree {
	int T[1600010], lazy[1600010];
	Segment_tree() {
		memset(T, 0, sizeof(T)), memset(lazy, 0, sizeof(lazy));
	}
	void pushup(int now) {
		T[now] = max(T[now << 1], T[now << 1 | 1]);
	}
	void pushdown(int now) {
		chmax(T[now << 1], lazy[now]), chmax(lazy[now << 1], lazy[now]);
		chmax(T[now << 1 | 1], lazy[now]), chmax(lazy[now << 1 | 1], lazy[now]);
		lazy[now] = 0;
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (L > R) return ;
		if (l == L && r == R) {
			chmax(T[now], x), chmax(lazy[now], x);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	int Query(int now, int l, int r, int pos) {
		if (l == r) return T[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) return Query(now << 1, l, mid, pos);
		return Query(now << 1 | 1, mid + 1, r, pos);
	}
}seg1, seg2;

set <int> S;

int main () {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		int x, y; char op[4]; scanf("%d%d%s", &X[i], &Y[i], op);
		OP[i] = op[0];
		all.push_back(X[i]), all.push_back(Y[i]);
	}
	all.push_back(0);
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	N = all.size();
	for (int i = 0; i < q; i++) {
		int x = lower_bound(all.begin(), all.end(), X[i]) - all.begin();
		int y = lower_bound(all.begin(), all.end(), Y[i]) - all.begin();
		if (S.count(x)) {
			printf("0\n");
			continue;
		}
		S.insert(x);
		if (OP[i] == 'U') {
			int pos = seg1.Query(1, 1, N, x);
			printf("%d\n", all[y] - all[pos]);
			seg2.Update(1, 1, N, pos + 1, y, x);
		} else {
			int pos = seg2.Query(1, 1, N, y);
			printf("%d\n", all[x] - all[pos]);
			seg1.Update(1, 1, N, pos + 1, x, y);
		}
	}
	return 0;
}