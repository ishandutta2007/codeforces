#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;

pii operator - (const pii &A, const pii &B) {
	return mp(A.fi - B.fi, A.se - B.se);
}

long long operator ^ (const pii &A, const pii &B) {
	return 1ll * A.fi * B.se - 1ll * A.se * B.fi;
}

int operator & (const pii &A, const int &x) {
	return A.se - A.fi * x;
}

int a[20010];
int f[20010], g[20010];
int pre[20010], suc[20010];

namespace HULL {
	bool IsBad(pii a, pii b, pii c) {return (b - a ^ c - a) <= 0;}
	deque <pii> q;
	void clear() {q.clear();}
	void push_front(pii x) {
		if (q.size() && q.front().fi == x.fi) x.se = min(x.se, q.front().se), q.pop_front();
		while (q.size() > 1 && IsBad(x, *q.begin(), *++q.begin())) q.pop_front();
		q.push_front(x);
	}
	void push_back(pii x) {
		if (q.size() && q.back().fi == x.fi) x.se = min(x.se, q.back().se), q.pop_back();
		while (q.size() > 1 && IsBad(*----q.end(), *--q.end(), x)) q.pop_back();
		q.push_back(x);
	}
	int query(int k) {
		if (!q.size()) return INF;
		int l = 0, r = (int)q.size() - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if ((q[mid] & k) < (q[mid + 1] & k)) r = mid;
			else l = mid + 1;
		}
		return q[l] & k;
	}
	int query_back(int k) {
		while (q.size() > 1 && (*----q.end() & k) > (*--q.end() & k)) q.pop_back();
		return q.size() ? *--q.end() & k : INF;
	}
	int query_front(int k) {
		while (q.size() > 1 && (*++q.begin() & k) > (*q.begin() & k)) q.pop_front();
		return q.size() ? *q.begin() & k : INF;
	}
}

void Solve(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	Solve(l, mid), Solve(mid + 1, r);
	for (int i = mid; i >= l; i--) {
		suc[i] = a[i + 1];
		if (i < mid) suc[i] = max(suc[i], suc[i + 1]);
	}
	for (int i = mid + 1; i <= r; i++) {
		pre[i] = a[i];
		if (i > mid + 1) pre[i] = max(pre[i], pre[i - 1]);
	}
	// for (int i = l; i <= mid; i++) {
	// 	for (int j = mid + 1; j <= r; j++) {
	// 		g[j] = min(g[j], f[i] + (max(suc[i], pre[j]) * (j - i)));
	// 	}
	// }
	{ // lef < rig
		int pos = mid;
		HULL :: clear();
		for (int i = mid + 1; i <= r; i++) {
			// for (int j = l; j <= mid; j++) {
			// 	if (suc[j] < pre[i]) g[i] = min(g[i], f[j] - j * pre[i] + pre[i] * i);
			// }
			while (pos >= l && suc[pos] < pre[i]) HULL :: push_front(mp(pos, f[pos])), pos--;
			g[i] = min(g[i], HULL :: query(pre[i]) + pre[i] * i);
		}
	}
	{ // lef >= rig
		int pos = l;
		HULL :: clear();
		for (int i = r; i >= mid + 1; i--) {
			// for (int j = l; j <= mid; j++) {
			// 	if (suc[j] >= pre[i]) g[i] = min(g[i], f[j] - j * suc[j] + suc[j] * i);
			// }
			while (pos <= mid && suc[pos] >= pre[i]) HULL :: push_back(mp(-suc[pos], f[pos] - pos * suc[pos])), pos++;
			g[i] = min(g[i], HULL :: query(i));
		}
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i - 1], a[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[i] *= i;
	}
	f[0] = 0x3f3f3f3f;
	for (int it = 1; it < k; it++) {
		memset(g, 0x3f, sizeof(g));
		Solve(it, n);
		memcpy(f, g, sizeof(g));
	}
	printf("%d\n", f[n]);
	return 0;
}