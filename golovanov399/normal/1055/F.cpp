#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Seg {
	int l, r;

	inline bool empty() const {
		return l == r;
	}

	inline long long len() const {
		return r - l;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt();
	long long k;
	cin >> k;
	vector<long long> a(n);
	for (int i = 1; i < n; ++i) {
		int p = nxt() - 1;
		long long x;
		cin >> x;
		a[i] = a[p] ^ x;
	}

	sort(all(a));

	vector<pair<Seg, Seg>> segs;
	segs.push_back({{0, n}, {0, n}});
	long long ans = 0;
	for (int it = 61; it >= 0; --it) {
		long long bit = 1ll << it;
		vector<pair<Seg, Seg>> new_segs[2];
		long long cnt[2] = {0, 0};
		for (const auto& [fst, snd] : segs) {
			Seg fsts[2] = {fst, fst};
			Seg snds[2] = {snd, snd};
			int i = fst.l;
			while (i < fst.r && !(a[i] & bit)) {
				++i;
			}
			fsts[0].r = fsts[1].l = i;

			i = snd.l;
			while (i < snd.r && !(a[i] & bit)) {
				++i;
			}
			snds[0].r = snds[1].l = i;

			for (int i = 0; i < 2; ++i) {
				if (!fsts[i].empty()) {
					for (int j = 0; j < 2; ++j) {
						if (!snds[j].empty()) {
							new_segs[i ^ j].push_back({fsts[i], snds[j]});
							cnt[i ^ j] += (fsts[i].len()) * (snds[j].len());
						}
					}
				}
			}
		}

		if (cnt[0] >= k) {
			segs.swap(new_segs[0]);
		} else {
			segs.swap(new_segs[1]);
			k -= cnt[0];
			ans |= bit;
		}
	}

	cout << ans << "\n";

	return 0;
}