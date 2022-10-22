#include <bits/stdc++.h>
using namespace std;

int n, m, q;
set <int> all[200010][2];

void Xor(set <int> &S, int x) {
	if (S.count(x)) S.erase(x);
	else S.insert(x);
}

namespace SEG {
	int T[1 << 19], maxj[1 << 19], minj[1 << 19];
	void pushup(int now) {
		T[now] = T[now << 1] && T[now << 1 | 1] && minj[now << 1] > maxj[now << 1 | 1];
		minj[now] = min(minj[now << 1], minj[now << 1 | 1]);
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]);
	}
	void Build(int now, int l, int r) {
		if (l == r) {
			minj[now] = !all[l][0].size() ? 0x3f3f3f3f : *all[l][0].begin();
			maxj[now] = !all[l][1].size() ? -1 : *--all[l][1].end();
			T[now] = minj[now] > maxj[now];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Modify(int now, int l, int r, int pos, int y, int t) {
		if (l == r) {
			Xor(all[l][t], y);
			minj[now] = !all[l][0].size() ? 0x3f3f3f3f : *all[l][0].begin();
			maxj[now] = !all[l][1].size() ? -1 : *--all[l][1].end();
			T[now] = minj[now] > maxj[now];
			return ;
		}
		int mid = l + r >> 1;
		pos <= mid ? Modify(now << 1, l, mid, pos, y, t) : Modify(now << 1 | 1, mid + 1, r, pos, y, t);
		pushup(now);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	SEG :: Build(1, 0, n - 1);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		SEG :: Modify(1, 0, n - 1, x >> 1, y >> 1, y & 1);
		printf(SEG :: T[1] ? "YES\n" : "NO\n");
	}
	return 0;
}