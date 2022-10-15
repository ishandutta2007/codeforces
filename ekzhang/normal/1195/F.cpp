#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXV 300013
int N, Q;
vector<pair<int, int> > deltas;
int idx[MAXN];
map<pair<int, int>, int> m;
vector<pair<int, int> > by_s[MAXV];
int ans[MAXN];
int fen[MAXV];

inline int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void upd(int i, int x) {
	for (++i; i < MAXV; i += i & -i)
		fen[i] += x;
}

int qry(int i) {
	int ret = 0;
	for (++i; i; i -= i & -i)
		ret += fen[i];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		vector<pair<int, int> > v(k);
		for (int j = 0; j < k; j++) {
			int x, y; cin >> x >> y;
			v[j].first += x;
			v[j].second += y;
			v[(j + 1) % k].first -= x;
			v[(j + 1) % k].second -= y;
		}
		for (auto& p : v) {
			int g = gcd(abs(p.first), abs(p.second));
			p.first /= g;
			p.second /= g;
		}
		deltas.insert(deltas.end(), v.begin(), v.end());
		idx[i + 1] = deltas.size();
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r; --l;
		by_s[idx[l]].emplace_back(idx[r], i);
	}

	for (int i = deltas.size() - 1; i >= 0; i--) {
		if (m.count(deltas[i])) {
			upd(m[deltas[i]], -1);
		}
		m[deltas[i]] = i;
		upd(i, +1);
		for (auto p : by_s[i]) {
			ans[p.second] = qry(p.first - 1);
		}
	}

	for (int i = 0; i < Q; i++)
		cout << ans[i] << '\n';

	cout.flush();
	return 0;
}