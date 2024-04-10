#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXSEG 262144
#define MAXD 20
int N, M, X;
int A[MAXN];

struct node {
	int fst[20], lst[20];
	LL num;
} st[MAXSEG];

node combine(const node& a, const node& b, int lo, int m, int hi) {
	node n;
	n.num = a.num + b.num;
	vector<pair<int, int> > av, bv;
	for (int i = 0; i < 20; i++) {
		n.fst[i] = min(a.fst[i], b.fst[i]);
		n.lst[i] = max(a.lst[i], b.lst[i]);
		if (a.lst[i] != -1) av.emplace_back(a.lst[i], 1<<i);
		if (b.fst[i] != N) bv.emplace_back(b.fst[i], 1<<i);
	}
	av.emplace_back(m, 0);
	bv.emplace_back(m + 1, 0);
	sort(av.begin(), av.end(), greater<pair<int, int> >());
	sort(bv.begin(), bv.end());

	for (int i = 0; i + 1 < av.size(); i++) {
		av[i + 1].second |= av[i].second;
	}

	int pre = lo - 1;
	int idx = 0, cur = 0;
	for (int i = av.size() - 1; i >= 0; i--) {
		int amt = av[i].first - pre;
		pre = av[i].first;
		int k = av[i].second;
		while (idx < bv.size() && (cur | k) < X) {
			++idx;
			if (idx < bv.size())
				cur |= bv[idx].second;
		}
		if (idx == bv.size())
			break;
		n.num += (LL) amt * (hi - bv[idx].first + 1);
	}

	return n;
}

void init(int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (lo == hi) {
		for (int i = 0; i < 20; i++) {
			st[node].fst[i] = ((A[lo] & (1<<i)) ? lo : N);
			st[node].lst[i] = ((A[lo] & (1<<i)) ? lo : -1);
		}
		st[node].num = A[lo] >= X ? 1 : 0;
		return;
	}
	int mid = (lo + hi) / 2;
	init(lo, mid, 2 * node + 1);
	init(mid + 1, hi, 2 * node + 2);
	st[node] = combine(st[2 * node + 1], st[2 * node + 2], lo, mid, hi);
	// cout << "INIT:" << lo << ' ' << hi << ' ' << st[node].num << endl;
}

void update(int i, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (lo > i || hi < i) return;
	if (lo == hi) {
		for (int j = 0; j < 20; j++) {
			st[node].fst[j] = ((A[i] & (1<<j)) ? i : N);
			st[node].lst[j] = ((A[i] & (1<<j)) ? i : -1);
		}
		st[node].num = A[i] >= X ? 1 : 0;
		return;
	}
	int mid = (lo + hi) / 2;
	update(i, lo, mid, 2 * node + 1);
	update(i, mid + 1, hi, 2 * node + 2);
	st[node] = combine(st[2 * node + 1], st[2 * node + 2], lo, mid, hi);
}

node query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (s <= lo && hi <= e)
		return move(st[node]);
	int mid = (lo + hi) / 2;
	if (mid < s)
		return query(s, e, mid + 1, hi, 2 * node + 2);
	if (mid >= e)
		return query(s, e, lo, mid, 2 * node + 1);
	return combine(query(s, e, lo, mid, 2 * node + 1),
		query(s, e, mid + 1, hi, 2 * node + 2), max(s, lo), mid, min(e, hi));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> X;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	init();

	while (M--) {
		int t; cin >> t;
		if (t == 1) {
			// update
			int i, y;
			cin >> i >> y; --i;
			A[i] = y;
			update(i);
		}
		else {
			// query
			int l, r;
			cin >> l >> r; --l, --r;
			cout << query(l, r).num << '\n';
		}
	}

	cout.flush();
	return 0;
}