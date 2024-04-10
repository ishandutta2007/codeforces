#include <bits/stdc++.h>
using namespace std;

int n;
int a[500010][3];

namespace SEG {
	struct Node {
		int lef[3], rig[3];
		int tot;
		void init(int a[3]) {
			tot = 0;
			for (int i = 0; i < 3; i++) {
				rig[i] = lef[i] = a[i] ? i + 1 : 0;
				tot += a[i];
			}
			for (int i = 0; i < 2; i++) {
				if (a[i] && a[i + 1]) lef[i + 1] = lef[i], rig[i + 1] = rig[i], tot--;
			}
		}
	};
	Node operator + (const Node &A, const Node &B) {
		static int fa[20]; for (int i = 1; i <= 12; i++) fa[i] = i;
		auto _find = [&](int x, auto _find) -> int {return x == fa[x] ? x : fa[x] = _find(fa[x], _find);};
		auto find = [&](int x) -> int {return _find(x, _find);};
		auto merge = [&](int x, int y) -> int {
			x = find(x), y = find(y);
			if (x == y) return 0;
			fa[y] = x;
			return 1;
		};
		Node C; C.tot = A.tot + B.tot;
		for (int i = 0; i < 3; i++) {
			if (A.rig[i] && B.lef[i]) C.tot -= merge(A.rig[i], 6 + B.lef[i]);
		}
		static int id[20]; for (int i = 1; i <= 12; i++) id[i] = 0;
		int N = 0;
		auto GetId = [&](int x) -> int {
			if (!x) return 0;
			x = find(x);
			return id[x] ? id[x] : id[x] = ++N;
		};
		for (int i = 0; i < 3; i++) {
			C.lef[i] = GetId(A.lef[i]), C.rig[i] = B.rig[i] ? GetId(6 + B.rig[i]) : 0;
		}
		return C;
	}
	Node T[1 << 20];
	void pushup(int now) {
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now].init(a[l]);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	Node Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}

int main() {
	scanf("%d", &n);
	for (int j = 0; j < 3; j++) {
		static char buf[500010]; scanf("%s", buf);
		for (int i = 1; i <= n; i++) {
			a[i][j] = buf[i - 1] - '0';
		}
	}
	SEG :: Build(1, 1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", SEG :: Query(1, 1, n, l, r).tot);
	}
	return 0;
}