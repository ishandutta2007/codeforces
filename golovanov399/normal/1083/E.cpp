#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Rect {
	long long x, y;
	long long a;
	long long ans;

	bool operator <(const Rect& ot) const {
		return x < ot.x;
	}
};

const long long md = 1e18;

struct Num {
	long long a, b;

	pair<long long, long long> asPair() const {
		return {a, b};
	}

	bool operator <(const Num& ot) const {
		return asPair() < ot.asPair();
	}

	Num operator +(const Num& ot) const {
		long long aa = a + ot.a;
		long long bb = b + ot.b;
		if (bb >= md) {
			++aa;
			bb -= md;
		}
		return {aa, bb};
	}
};

Num prod(long long x, long long y) {
	Num a = {x / md, x % md};
	Num res = {0, 0};
	while (y) {
		if (y & 1ll) {
			res = res + a;
		}
		y >>= 1;
		a = a + a;
	}
	return res;
}

bool cmp(long long x, long long y, long long z, long long t) {
	// returns x * y >= z * t
	return !(prod(x, y) < prod(z, t));
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<Rect> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].x = nxt();
		a[i].y = nxt();
		scanf("%lld", &a[i].a);
	}
	sort(all(a));

	vector<pair<long long, long long>> ch;
	long long ans = 0;
	int cur_ptr = -1;

	for (int i = 0; i < n; ++i) {
		long long ch_tmp = -1e18;
		if (cur_ptr > -1 && cur_ptr < (int)ch.size()) {
			ch_tmp = ch[cur_ptr].second - ch[cur_ptr].first * a[i].y;
		}
		while (cur_ptr + 1 < (int)ch.size() && ch[cur_ptr + 1].second - ch[cur_ptr + 1].first * a[i].y >= ch_tmp) {
			ch_tmp = ch[cur_ptr + 1].second - ch[cur_ptr + 1].first * a[i].y;
			++cur_ptr;
		}

		ans = max(ans, a[i].ans = a[i].x * a[i].y - a[i].a + max(0ll, ch_tmp));

		if (!ch.empty() && ch.back().second >= a[i].ans) {
			continue;
		}
		int sz = ch.size();
		while (sz >= 2 &&
			   cmp(ch[sz - 1].first - ch[sz - 2].first, a[i].ans - ch[sz - 1].second,
				   ch[sz - 1].second - ch[sz - 2].second, a[i].x - ch[sz - 1].first)) {
			ch.pop_back();
			--sz;
		}
		ch.push_back({a[i].x, a[i].ans});

		cur_ptr = min(cur_ptr, (int)ch.size() - 1);
		if (cur_ptr < 0 && (int)ch.size() >= 0) {
			cur_ptr = 0;
		}
	}

	cout << ans << "\n";

	return 0;
}