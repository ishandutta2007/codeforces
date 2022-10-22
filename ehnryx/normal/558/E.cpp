#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<17;
struct SegTree {
	int t[2*N], d[2*N];
	SegTree() {
		memset(t, 0, sizeof t);
		memset(d, -1, sizeof d);
	}

	void build() {
		for (int i = N-1; i > 0; i--) {
			t[i] = t[2*i] + t[2*i+1];
		}
	}

	void push(int i, int len) {
		if (d[i] != -1) {
			d[2*i] = d[2*i+1] = d[i];
			t[2*i] = t[2*i+1] = d[i] * len/2;
			d[i] = -1;
		}
	}

	void pull(int i) {
		t[i] = t[2*i] + t[2*i+1];
	}

	void update(int left, int right, int v, int i=1, int l=0, int r=N-1) {
		if (r < left || right < l) return;
		if (left <= l && r <= right) {
			d[i] = v;
			t[i] = v * (r-l+1);
			return;
		}
		push(i, r-l+1);

		int mid = (l+r)/2;
		update(left, right, v, 2*i, l, mid);
		update(left, right, v, 2*i+1, mid+1, r);
		pull(i);
	}

	int query(int left, int right, int i=1, int l=0, int r=N-1) {
		if (r < left || right < l) return 0;
		if (left <= l && r <= right) {
			return t[i];
		}
		push(i, r-l+1);

		int mid = (l+r)/2;
		return query(left, right, 2*i, l, mid) + query(left, right, 2*i+1, mid+1, r);
	}
};

SegTree segt[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		segt[s[i]-'a'].t[i+N] = 1;
	}
	for (int i = 0; i < 26; i++) {
		segt[i].build();
	}

	int a, b, inc;
	while (q--) {
		cin >> a >> b >> inc;
		--a, --b;
		int pos = a;
		for (int i = 0; i < 26; i++) {
			int id = inc ? i : 26-1-i;
			int add = segt[id].query(a, b);
			segt[id].update(a, b, 0);
			segt[id].update(pos, pos + add - 1, 1);
			pos += add;
		}
	}

	cerr << n << nl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (segt[j].query(i, i)) {
				cout << (char)(j+'a');
			}
		}
	}
	cout << nl;

	return 0;
}