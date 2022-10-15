#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define MAXN 300013
#define MAXSEG (1<<20)
#define MOD 1000000009

int N, M;
int A[MAXN];
int f[MAXN], fp[MAXN];
int st[MAXSEG], lazy[MAXSEG][2];

inline int add(int x, int y) { return (x + y) % MOD; }
inline int sub(int x, int y) { return (x - y + MOD) % MOD; }
inline int mul(int x, int y) { return (LL) x * y % MOD; }

void push(int lo, int hi, int node) {
	int len = hi - lo + 1;
	int d = (lo + hi) / 2 + 1 - lo;
	if (lazy[node][0]) {
		st[node] = add(st[node], mul(lazy[node][0], fp[len + 1]));
		if (lo != hi) {
			lazy[2 * node + 1][0] = add(lazy[2 * node + 1][0], lazy[node][0]);
			lazy[2 * node + 2][0] = add(lazy[2 * node + 2][0], mul(lazy[node][0], f[d + 1]));
			lazy[2 * node + 2][1] = add(lazy[2 * node + 2][1], mul(lazy[node][0], f[d]));
		}
		lazy[node][0] = 0;
	}
	if (lazy[node][1]) {
		st[node] = add(st[node], mul(lazy[node][1], fp[len]));
		if (lo != hi) {
			lazy[2 * node + 1][1] = add(lazy[2 * node + 1][1], lazy[node][1]);
			lazy[2 * node + 2][0] = add(lazy[2 * node + 2][0], mul(lazy[node][1], f[d]));
			lazy[2 * node + 2][1] = add(lazy[2 * node + 2][1], mul(lazy[node][1], f[d - 1]));
		}
		lazy[node][1] = 0;
	}
}

void build_tree(int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (lo == hi) { st[node] = A[lo]; return; }
	int mid = (lo + hi) / 2;
	build_tree(lo, mid, 2 * node + 1);
	build_tree(mid + 1, hi, 2 * node + 2);
	st[node] = add(st[2 * node + 1], st[2 * node + 2]);
}

void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(lo, hi, node);
	if (lo > e || hi < s) return;
	if (s <= lo && hi <= e) {
		lazy[node][0] = mul(x, f[lo - s + 1]);
		lazy[node][1] = mul(x, f[lo - s]);
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = add(st[2 * node + 1], st[2 * node + 2]);
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(lo, hi, node);
	if (lo > e || hi < s) return 0;
	if (s <= lo && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return add(query(s, e, lo, mid, 2 * node + 1), query(s, e, mid + 1, hi, 2 * node + 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	f[1] = 1;
	for (int i = 2; i <= N + 2; i++) {
		f[i] = add(f[i - 1], f[i - 2]);
		fp[i] = add(fp[i - 1], f[i - 1]);
	}

	for (int i = 0; i < N; i++)
		cin >> A[i];

	build_tree();

	while (M--) {
		int t, l, r;
		cin >> t >> l >> r; --l, --r;
		if (t == 1)
			update_range(l, r, 1);
		else
			cout << query(l, r) << '\n';
	}

	cout.flush();
	return 0;
}