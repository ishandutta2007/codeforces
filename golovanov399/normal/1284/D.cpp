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

struct Shit {
	int n;
	vector<pair<int, int>> segs;
	vector<long long> values;
	map<int, long long> pref;
	map<int, long long> suf;

	Shit(const vector<pair<int, int>>& _segs, const vector<long long>& _values): n(_segs.size()), segs(_segs), values(_values) {
		{
			vector<pair<int, int>> endpoints;
			for (int i = 0; i < n; ++i) {
				endpoints.push_back({segs[i].second, i});
			}
			sort(all(endpoints));
			long long cur = 0;
			for (auto [e, i] : endpoints) {
				cur += values[i];
				pref[e] = cur;
			}
		}
		{
			vector<pair<int, int>> begpoints;
			for (int i = 0; i < n; ++i) {
				begpoints.push_back({segs[i].first, i});
			}
			sort(all(begpoints));
			reverse(all(begpoints));
			long long cur = 0;
			for (auto [e, i] : begpoints) {
				cur += values[i];
				suf[e] = cur;
			}
		}
	}

	long long get(int i) {
		auto pit = pref.lower_bound(segs[i].first);
		auto sit = suf.upper_bound(segs[i].second);
		return (pit == pref.begin() ? 0 : prev(pit)->second) + (sit == suf.end() ? 0 : sit->second);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> values;
	for (int i = 0; i < n; ++i) {
		values.push_back(rand());
		values.back() <<= 32;
		values.back() |= rand();
	}

	vector<pair<int, int>> segs[2];
	segs[0].resize(n);
	segs[1].resize(n);
	for (int i = 0; i < n; ++i) {
		segs[0][i].first = nxt();
		segs[0][i].second = nxt();
		segs[1][i].first = nxt();
		segs[1][i].second = nxt();
	}

	Shit left(segs[0], values);
	Shit right(segs[1], values);

	for (int i = 0; i < n; ++i) {
		if (left.get(i) != right.get(i)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}