#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
4
5
1 2 3 4 5
2
10
2 4 2 4 2 4 2 4 2 4
3
3
-10 -5 -10
-8
3
9 9 -3
5

*/
/*input
1
5
1 1 1 1 1
2

*/

bool pagal_t = false;

struct pora {
	long long t;
	int k;
	bool operator<(const pora &x)const {
		if (pagal_t) {
			return t > x.t;
		}

		return k < x.k;
	}
};

ostream &operator<<(ostream &o, const pora &x) {
	return o << "[" << x.t << " " << x.k << "]";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt;
	cin >> tt;

	while (tt--) {
		long long n;
		cin >> n;
		vector<long long> a(n);

		for (auto &&x : a) {
			cin >> x;
		}

		long long k;
		cin >> k;

		for (int i = 0; i < n; ++i) {
			a[i] -= k;
		}

		int ans = 1;

		set<pora> b;

		auto add = [&](long long t, int x) -> void {
			ans = max(ans, x);
			pagal_t = false;
			auto it = b.lower_bound({0, x});

			if (it != b.end() and it -> t >= t) {
				return;
			}

			while (it != b.begin()) {
				auto it2 = it;
				--it2;

				if (it2->t <= t) {
					b.erase(it2);
				}
				else {
					break;
				}
			}

			if (it != b.end() and it->k == x) {
				b.erase(it);
			}

			b.insert({t, x});
		};

		for (int i = 0; i < n; ++i) {
			debug(i, a[i]);
			pora oo;
			bool f = false;

			if (b.size()) {
				auto it = b.end();
				it--;
				oo = *it;
				f = true;
			}

			pagal_t = true;
			auto it = b.upper_bound({-a[i], 0});

			if (it != b.begin()) {
				it--;
				long long tt = min(it->t + a[i], a[i]);

				if (it->t + a[i] >= 0) {
					add(tt, it->k + 1);
				}
			}

			if (f) {
				add(10000000000000000ll, oo.k);
			}

			add(a[i], 1);

			debug(b);
		}

		cout << ans << "\n";
	}

}