#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;

const int S = 1 << 18;
struct {
	int minVal = 0;
} seg[2 * S];
map<int, int> lows;

struct seg_node {
	seg_node* ch[2] = { nullptr, nullptr };
	ll a = 0, b = 0;
};

void init() {
	lows[-1] = int(1.1e9);
	lows[0] = 0;
	lows[S] = 0;
}

int queryPrefMin(int a) {
	int ans = seg[S + a].minVal;
	for (int l = S, r = S + a; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			ans = min(ans, seg[l].minVal);
			l++;
		}
		if (r & 1) {
			r--;
			ans = min(ans, seg[r].minVal);
		}
	}
	return ans;
}

seg_node* update_seg(seg_node* n, int l, int r, ll a, ll b, int x = 0, int y = S) {
	assert(l < r);
	if (n == nullptr) {
		n = new seg_node();
	} else {
		n = new seg_node(*n);
	}

	if (l <= x && y <= r) {
		n->a += a;
		n->b += b;
	} else {
		int z = (x + y) / 2;
		if (l < z) {
			n->ch[0] = update_seg(n->ch[0], l, r, a, b, x, z);
		}
		if (z < r) {
			n->ch[1] = update_seg(n->ch[1], l, r, a, b, z, y);
		}
	}
	return n;
}

seg_node* ROOTS[MAXN];

ll query_seg(seg_node* n, int p, ll fac, int x = 0, int y = S) {
	assert(x <= p && p < y);

	if (n == nullptr) return 0;

	ll res = n->a * fac + n->b;

	if (y - x > 1) {
		int z = (x + y) / 2;
		if (p < z) {
			res += query_seg(n->ch[0], p, fac, x, z);
		} else {
			res += query_seg(n->ch[1], p, fac, z, y);
		}
	}

	return res;
}

void doUpdate(int A) {
	N++;
	ROOTS[N] = ROOTS[N-1];
	seg[S + A].minVal = N;
	for (int a = (S + A) / 2; a > 0; a /= 2) {
		seg[a].minVal = min(seg[2 * a].minVal, seg[2 * a + 1].minVal);
	}
	if (lows.count(A)) {
		auto pt = lows.find(A);
		--pt;

		auto jt = lows.find(A);
		++jt;

		int oldV = lows[A];
		lows.erase(A);
		int x = A, y = jt->first;
		// recompute [x, y), put the intervals in
		while (x < y) {
			int v = queryPrefMin(x);
			int mi = x, ma = y;
			while (ma - mi > 1) {
				int md = (mi + ma) / 2;
				if (queryPrefMin(md) == v) {
					mi = md;
				} else {
					ma = md;
				}
			}
			//cerr << "update_seg " << x << ' ' << ma << ' ' << oldV << "->" << v << '\n';
			ROOTS[N] = update_seg(ROOTS[N], x, ma, (v - oldV), -ll(v - oldV) * ll(N-1));
			if (v == pt->second) {
				// do nothing
			} else {
				lows[x] = v;
			}
			x = ma;
		}
	}
}

ll doQuery(int L, int R, int K) {
	//cerr << "doQuery " << L << ' ' << R << ' ' << K << '\n';
	if (K < 0) {
		//cerr <<  ll(R - L + 2) * ll(R - L + 1) / 2 << '\n';
		return ll(R - L + 2) * ll(R - L + 1) / 2;
	}

	// number of ranges including K
	auto queryPt = [&](int r) { 
		return query_seg(ROOTS[r], K, r);
	};
	int mi = L-1;
	int ma = R+1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		//cerr << md << ' ' << queryPt(md) - queryPt(md - 1) << '\n';
		if (queryPt(md) - queryPt(md - 1) >= L) {
			ma = md;
		} else {
			mi = md;
		}
	}
	if (ma > R) return 0;
	// ma .. R, inclusive
	//cerr << L << ' ' << R << ' ' << K << ' ' << ma << '\n';
	//cerr << queryPt(R) << ' ' << queryPt(mi) << '\n';
	//cerr << ll(R + ma) * ll(R-mi) / 2 << '\n';
	return (queryPt(R) - queryPt(mi)) - ll(L-1) * ll(R - mi);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	ll lastAns = 0;
	init();
	for (int q = 1; q <= Q; q++) {
		ll A_, L_, R_, K_; cin >> A_ >> L_ >> R_ >> K_;
		int A = int((A_ + lastAns) % (Q+1));
		int L = int((L_ + lastAns) % q + 1);
		int R = int((R_ + lastAns) % q + 1);
		if (L > R) swap(L, R);
		int K = int((K_ + lastAns) % (Q+1));
		//cerr << "query " << A << ' ' << L << ' ' << R << ' ' << K << '\n';
		doUpdate(A);
		ll ans = doQuery(L, R, K-1) - doQuery(L, R, K);
		//cerr << "answer " << ans << '\n';
		cout << ans << '\n';
		lastAns = ans;
	}

	return 0;
}