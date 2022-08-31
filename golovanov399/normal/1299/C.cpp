#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Segm {
	long long sum;
	int len;
	int last;

	bool operator <(const Segm& ot) const {
		return sum * ot.len < ot.sum * len;
	}
};

Segm merge(const Segm& l, const Segm& r) {
	return {l.sum + r.sum, l.len + r.len, r.last};
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<Segm> st;
	for (int i = 0; i < n; ++i) {
		Segm cur = {1ll * a[i], 1, i};
		while (!st.empty() && cur < st.back()) {
			cur = merge(st.back(), cur);
			st.pop_back();
		}
		st.push_back(cur);
	}

	for (const auto& s : st) {
		for (int i = 0; i < s.len; ++i) {
			printf("%.10Lf\n", (long double)s.sum / s.len);
		}
	}

	return 0;
}