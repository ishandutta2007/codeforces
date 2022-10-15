#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXSEG 262144
#define MAGIC -11234567890123LL
int N, Q;
LL A[MAXN];
LL pk[MAXN], ppk[MAXN];
LL st[MAXSEG], lazy[MAXSEG];
set<pair<int, LL> > delta;

void push(int lo, int hi, int node) {
	if (lazy[node] != MAGIC) {
		st[node] = (hi - lo + 1) * lazy[node];
		if (lo != hi) {
			lazy[2 * node + 1] = lazy[node];
			lazy[2 * node + 2] = lazy[node];
		}
		lazy[node] = MAGIC;
	}
}

void update_range(int s, int e, LL x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1)
		hi = N - 1;
	push(lo, hi, node);
	if (lo > e || hi < s)
		return;
	if (s <= lo && hi <= e) {
		lazy[node] = x;
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}

LL query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1)
		hi = N - 1;
	push(lo, hi, node);
	if (lo > e || hi < s)
		return 0;
	if (s <= lo && hi <= e)
		return st[node];
	int mid = (lo + hi) / 2;
	return query(s, e, lo, mid, 2 * node + 1) +
		query(s, e, mid + 1, hi, 2 * node + 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N - 1; i++) {
		cin >> pk[i + 1];
		pk[i + 1] += pk[i];
		ppk[i + 1] = pk[i + 1] + ppk[i];
	}

	for (int i = 0; i < N; i++)
		A[i] -= pk[i];

	// init st and ds
	fill(lazy, end(lazy), MAGIC);
	for (int i = 0; i < N; i++) {
		update_range(i, i, A[i]);
		delta.emplace(i, A[i]); // monotonic i think
	}

	cin >> Q;
	while (Q--) {
		string typ; cin >> typ;
		if (typ[0] == '+') {
			int i; LL x;
			cin >> i >> x; --i;
			x += query(i, i);
			int nxt = i + 1;
			while (true) {
				auto it = delta.lower_bound({ i, MAGIC });
				if (it == delta.end()) {
					nxt = N;
					break;
				}
				nxt = it->first;
				if (it->second <= x)
					delta.erase(it);
				else
					break;
			}
			update_range(i, nxt - 1, x);
			delta.emplace(i, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << query(l, r) + ppk[r] - (l ? ppk[l - 1] : 0) << '\n';
		}
	}

	cout.flush();
	return 0;
}