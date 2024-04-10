#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int block = 200;

struct Query {
	int l, r, idx;
	int64_t ord;
	
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<Query> w(q);
	for (int i = 0; i < q; i++) {
		cin >> w[i].l >> w[i].r;
		w[i].l--; w[i].r--;
		w[i].idx = i;
		w[i].ord = gilbertOrder(w[i].l, w[i].r, 21, 0);
	}
	
	vector<int> knt(1e6 + 42);
	int64_t ans = 0;
	int l = 0, r = 0;
	
	auto add = [&](int64_t x) {
		ans += x * (2*knt[x] + 1);
		knt[x]++;
	};
	
	auto del = [&](int64_t x) {
		knt[x]--;
		ans -= x * (2*knt[x] + 1);
	};
	
	block = sqrt(n) + 1;
	add(v[0]);
	sort(w.begin(), w.end(), [&](const Query &a, const Query &b) {
		return a.ord < b.ord;
		//return a.toPair() < b.toPair();
	});
	
	vector<int64_t> res(q);
	for (Query q: w) {
		while (r < q.r) {
			add(v[++r]);
		}
		while (l > q.l) {
			add(v[--l]);
		}
		while (r > q.r) {
			del(v[r--]);
		}
		while (l < q.l) {
			del(v[l++]);
		}
		res[q.idx] = ans;
	}
	
	for (int i = 0; i < q; i++) {
		cout << res[i] << "\n";
	}
	
	return 0;
}