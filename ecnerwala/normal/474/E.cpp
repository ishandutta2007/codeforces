#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;
int N;

ll D;
ll H[MAXN];

const int MAXV = MAXN;
int V;
ll vals[MAXV];

template <class T> struct bit {

	T b[MAXV];

	T getmax(int a) {
		T res;
		for(int i = a; i > 0; i -= i & (-i)) {
			res = max(res, b[i]);
		}
		return res;
	}

	void setmax(int a, T v) {
		a++;
		for(int i = a; i <= V; i += i & (-i)) {
			b[i] = max(b[i], v);
		}
	}

	bit () {
		memset(b, 0, sizeof(b));
	}
};

bit<pii> bt[2];

int prv[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	cin >> D;
	for(int i = 0; i < N; i++) cin >> H[i];

	V = 0;
	for(int i = 0; i < N; i++) {
		vals[V++] = H[i];
	}
	sort(vals, vals + V);
	V = unique(vals, vals + V) - vals;

	pii res;
	for(int i = N - 1; i >= 0; i--) {
		pii len1 = bt[0].getmax(upper_bound(vals, vals + V, H[i] - D) - vals);
		pii len2 = bt[1].getmax(V - (lower_bound(vals, vals + V, H[i] + D) - vals));
		pii len = max(len1, len2);
		int ind = lower_bound(vals, vals + V, H[i]) - vals;
		prv[i + 1] = len.B;
		len.A ++;
		len.B = i + 1;
		res = max(res, len);
		bt[0].setmax(ind, len);
		bt[1].setmax(V - 1 - ind, len);
	}

	cerr << res.A << ' ' << res.B << '\n';
	cout << res.A << '\n';
	for(int cur = res.B; cur; cur = prv[cur]) {
		cout << cur << ' ';
	}
	cout << '\n';

	return 0;
}