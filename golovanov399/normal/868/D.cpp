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

const int K = 18;

struct String {
	array<bitset<(1 << K)>, K> a;
	string start, finish;

	String() {
		a[0][0] = 1;
	}

	String(const string& s) {
		a[0][0] = 1;
		for (int l = 1; l <= (int)s.length() && l < K; ++l) {
			int cur = 0;
			for (int i = 0; i < (int)s.length(); ++i) {
				cur = (cur * 2 + (s[i] - '0')) & ((1 << l) - 1);
				if (i >= l - 1) {
					a[l][cur] = 1;
				}
			}
		}

		start = s.substr(0, min((int)s.length(), K));
		finish = s.substr((int)s.length() - min((int)s.length(), K));
	}

	int get() {
		for (int i = 0; i < K; ++i) {
			if ((int)a[i].count() < (1 << i)) {
				return i - 1;
			}
		}
		return K - 1;
	}
};

String merge(const String& fs, const String& sn) {
	String res(fs.finish + sn.start);
	if (fs.start.length() >= K) {
		res.start = fs.start;
	}
	if (sn.finish.length() >= K) {
		res.finish = sn.finish;
	}
	for (int i = 0; i < K; ++i) {
		res.a[i] |= fs.a[i] | sn.a[i];
	}

	return res;
}

int main() {
	int n = nxt();
	vector<String> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[i] = String(s);
	}

	int m = nxt();
	a.reserve(n + m);
	while (m--) {
		int i = nxt() - 1, j = nxt() - 1;
		a.push_back(merge(a[i], a[j]));

		printf("%d\n", a.back().get());
	}

	return 0;
}