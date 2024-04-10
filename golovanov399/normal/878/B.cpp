#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define int long long

int k;

vector<pair<int, int>> merge(vector<pair<int, int>> fst, vector<pair<int, int>> snd) {
	int i = 0;
	while (i < (int)snd.size() && !fst.empty()) {
		if (fst.back().first == snd[i].first) {
			if ((fst.back().second + snd[i].second) % k == 0) {
				fst.pop_back();
				++i;
			} else {
				snd[i].second = (fst.back().second + snd[i].second) % k;
				fst.pop_back();
				break;
			}
		} else {
			break;
		}
	}
	while (i < (int)snd.size()) {
		fst.push_back(snd[i++]);
	}
	return fst;
}

int32_t main() {
	int n = nxt();
	k = nxt();
	int m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<pair<int, int>> b;
	for (int x : a) {
		if (b.empty() || x != b.back().first) {
			b.push_back({x, 1});
		} else {
			b.back().second += 1;
			if (b.back().second == k) {
				b.pop_back();
			}
		}
	}

	if (b.empty()) {
		puts("0");
		return 0;
	}

	if (b.size() == 1) {
		cout << 1ll * m * b[0].second % k << "\n";
		return 0;
	}

	auto c = merge(b, b);

	// for (auto p : b) {
	// 	cerr << "(" << p.first << ", " << p.second << ") ";
	// }
	// cerr << "\n";
	// for (auto p : c) {
	// 	cerr << "(" << p.first << ", " << p.second << ") ";
	// }
	// cerr << "\n";

	if (c.size() <= b.size()) {
		if (b.size() % 2 && c.size() == b.size()) {
			long long cnt = 0;
			for (auto p : c) {
				cnt += p.second;
			}
			cnt -= c[b.size() / 2].second;
			cnt += b[b.size() / 2].second * m % k;
			if (b[b.size() / 2].second * m % k == 0) {
				cnt = 0;
			}
			cout << cnt << "\n";
			return 0;
		}
		m %= 2;
		if (m == 0) {
			b = c;
		}
		long long cnt = 0;
		for (auto p : b) {
			cnt += p.second;
		}
		cout << cnt << "\n";
	} else {
		if (c.size() % 2) {
			int rest = b.size() - (c.size() + 1) / 2;
			long long cnt = 0;
			for (int i = rest + 1; i < (int)b.size() - rest - 1; ++i) {
				cnt += b[i].second;
			}
			cnt += c[c.size() / 2].second;
			cnt *= m;
			cnt -= c[c.size() / 2].second;
			for (int i = 0; i < rest + 1; ++i) {
				cnt += b[i].second;
			}
			for (int i = (int)b.size() - rest - 1; i < (int)b.size(); ++i) {
				cnt += b[i].second;
			}
			cout << cnt << "\n";
			return 0;
		}
		int cs = (c.size() + 1) / 2;
		int bs = b.size();
		long long cnt = 0;
		for (int i = bs - cs; i < cs; ++i) {
			cnt += b[i].second;
		}
		cnt *= m;
		for (int i = 0; i < bs - cs; ++i) {
			cnt +=b[i].second;
		}
		for (int i = cs; i < bs; ++i) {
			cnt += b[i].second;
		}
		cout << cnt << "\n";
	}

	return 0;
}