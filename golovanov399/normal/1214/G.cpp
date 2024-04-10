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
	// cin >> x;
	return x;
}

const int N = 2048;
using Bs = bitset<N>;

Bs pref[N];

bool check(const Bs& fst, const Bs& snd) {
	auto b = fst ^ snd;
	return (b & fst).count() && (b & snd).count();
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), q = nxt();

	pref[0] = {};
	for (int i = 1; i <= m; ++i) {
		pref[i] = pref[i - 1];
		pref[i].flip(i - 1);
	}

	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		S.insert({0, i});
	}

	set<int> good;
	vector<Bs> a(n, Bs{});
	vector<int> cnt(n);

	auto rem = [&](int idx) {
		auto it = S.find({cnt[idx], idx});
		if (it != S.begin() && good.count(prev(it)->second)) {
			good.erase(prev(it)->second);
		}
		if (good.count(it->second)) {
			good.erase(it->second);
		}
		if (it != S.begin() && next(it) != S.end() && check(a[prev(it)->second], a[next(it)->second])) {
			good.insert(prev(it)->second);
		}
		S.erase(it);
	};

	auto add = [&](int idx) {
		auto it = S.lower_bound({cnt[idx], idx});
		if (it != S.begin() && good.count(prev(it)->second)) {
			good.erase(prev(it)->second);
		}
		if (it != S.begin() && check(a[prev(it)->second], a[idx])) {
			good.insert(prev(it)->second);
		}
		S.insert({a[idx].count(), idx});
		if (it != S.end() && check(a[idx], a[it->second])) {
			good.insert(idx);
		}
	};

	while (q--) {
		int idx = nxt() - 1, l = nxt() - 1, r = nxt();
		rem(idx);
		a[idx] ^= pref[l];
		a[idx] ^= pref[r];
		cnt[idx] = a[idx].count();
		add(idx);

		if (good.empty()) {
			printf("%d\n", -1);
		} else {
			auto idx = *good.begin();
			auto it = S.find({cnt[idx], idx});
			int x1 = it->second;
			int x2 = next(it)->second;
			auto b = a[x1] ^ a[x2];
			int y1 = (b & a[x1])._Find_first();
			int y2 = (b & a[x2])._Find_first();
			if (x1 > x2) {
				swap(x1, x2);
			}
			if (y1 > y2) {
				swap(y1, y2);
			}
			printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
		}
	}

	return 0;
}