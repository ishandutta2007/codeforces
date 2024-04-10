#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long infty = 1000000000000000000ll;

/*input
3 4 5
10 30 15
12 31 14 18
0 1 2 3 4
*/
/*input
4 4 1
1 2 3 4
5 6 7 8
1
*/

typedef tree <
pair<int, int>,
	 null_type,
	 less<pair<int, int>>,
	 rb_tree_tag,
	 tree_order_statistics_node_update >
	 ordered_set;

long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n), b(m);
	vector<pair<long long, int>>qq(q);

	for (auto &&x : a) {
		cin >> x;
	}

	for (auto &&x : b) {
		cin >> x;
	}

	vector<pair<int, int>>ab;

	for (int i = 0; i < n; ++i) {
		ab.push_back({a[i], i});
	}

	for (int i = 0; i < m; ++i) {
		ab.push_back({b[i], -i - 1});
	}

	for (int i = 0; i < q; ++i) {
		cin >> qq[i].first;
		qq[i].second = i;
	}

	sort(qq.begin(), qq.end());
	sort(ab.begin(), ab.end());

	vector<pair<int, int>>bb;

	for (int i = 1; i < m + n; ++i) {
		bb.push_back({ab[i].first - ab[i - 1].first, i});
	}

	typedef pair<ordered_set *, int> Repr;
	set<pair<int, Repr>>bi;

	sort(bb.begin(), bb.end());

	int xxx = 0;

	auto uno = [&](int v, int k) -> Repr {
		auto t = new ordered_set();
		t->insert({v, xxx++});
		return {t, k};
	};

	for (int i = 0; i < m + n; ++i) {
		bi.insert({i, uno(ab[i].first, ab[i].second >= 0 ? 1 : 0)});
	}

	for (int i = 0; i < n; ++i) {
		ans += a[i];
	}

	auto merges = [&](Repr i, Repr j) -> Repr {
		if (i.first->size() < j.first->size()) {
			swap(i, j);
		}

		for (auto &&x : *j.first) {
			auto t = i.first->find_by_order(i.first->size() - i.second);

			if (i.second > 0 and x > *t) {
				ans -= t->first;
				ans += x.first;
			}

			i.first->insert(x);
		}

		for (int o = 0; o < j.second; ++o) {
			auto t2 = j.first->find_by_order(j.first->size() - 1 - o);
			ans -= t2->first;

			i.second++;
			auto t = i.first->find_by_order(i.first->size() - i.second);
			ans += t->first;
		}

		return i;
	};

	auto mergb = [&](int i, int j) -> void {
		auto it1 = bi.upper_bound({min(i, j), {(ordered_set *)-1, 0}});
		auto it2 = it1;

		if (it1 == bi.end() or it1->first > max(i, j) or bi.begin() == it2) {
			return;
		}

		it2--;
		pair<int, Repr> o = {min(it1->first, it2->first), merges(it1->second, it2->second)};
		bi.erase(it1);
		bi.erase(it2);
		bi.insert(o);
	};

	int bbp = 0;

	for (int i = 0; i < q; ++i) {
		int k = qq[i].first;

		while (bbp < bb.size() and bb[bbp].first <= k) {
			mergb(bb[bbp].second, bb[bbp].second - 1);
			bbp++;
		}

		qq[i].first = ans;
	}

	sort(qq.begin(), qq.end(), [](const auto & i, const auto & j) -> bool {
		return i.second < j.second;
	});

	for (int i = 0; i < q; ++i) {
		cout << qq[i].first << "\n";
	}
}