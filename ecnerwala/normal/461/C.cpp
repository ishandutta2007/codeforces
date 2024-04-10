#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

int N;

int bit[MAXN];

void insert(int a, int v) {
	assert(a > 0 && a <= N);
	for(int i = a; i <= N; i += i & (-i)) {
		bit[i] += v;
	}
}

int query(int a) {
	int res = 0;
	for(int i = a; i > 0; i -= i & (-i)) {
		res += bit[i];
	}
	return res;
}

// inclusive
int query(int l, int r) {
	if(l > r) swap(l, r);
	return query(r) - query(l - 1);
}

int main() {
	cin >> N;
	int L = 0;
	int R = N;
	int dir = 1;
	int Q; cin >> Q;
	for(int i = 1; i <= N; i++) {
		insert(i, 1);
	}
	for(int q = 0; q < Q; q++) {
		int t; cin >> t;
		if(t == 1) {
			int p; cin >> p;
			if(2 * p <= abs(R - L)) {
				for(int i = 1; i <= p; i++) {
					int v = query(L + i * dir, L + i * dir);
					insert(L + i * dir, -v);
					insert(L + (2 * p + 1 - i) * dir, v);
				}
				L += p * dir;
			} else {
				for(int i = p; i > p - (abs(R - L) - p); i--) {
					int v = query(L + (2 * p + 1 - i) * dir, L + (2 * p + 1 - i) * dir);
					insert(L + (2 * p + 1 - i) * dir, -v);
					insert(L + i * dir, v);
				}
				L = L + (p + 1) * dir;
				dir *= -1;
				R = L + p * dir;
			}
			//cerr << L << ' ' << R << ' ' << dir << '\n';
			//for(int i = 1; i <= dir * (R - L); i++) { cerr << query(L + i * dir, L + i * dir) << ' '; } cerr << '\n';
		} else {
			int l, r; cin >> l >> r;
			l++;
			cout << query(L + l * dir, L + r * dir) << '\n';
		}
	}
	return 0;
}