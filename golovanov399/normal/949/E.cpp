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

struct Seg {
	int l, r;

	bool has(int x) const {
		return (l <= x && x < r);
	}

	bool empty() const {
		return l >= r;
	}
};

Seg intersect(const Seg& fst, const Seg& snd) {
	int l = max(fst.l, snd.l);
	int r = min(fst.r, snd.r);
	if (l < r) {
		return {l, r};
	} else {
		return {0, 0};
	}
}

using Segs = vector<Seg>;

Segs intersect(const Segs& fst, const Segs& snd) {
	Segs result;
	for (auto f : fst) {
		for (auto s : snd) {
			auto r = intersect(f, s);
			if (!r.empty()) {
				result.push_back(r);
			}
		}
	}
	return result;
}

Segs getCyclic(int l, itn r, int len) {
	if (l < r) {
		return {{l, r}};
	} else {
		return {{l, len}, {0, r}};
	}
}

ostream& operator <<(ostream& ostr, const Segs& ss) {
	ostr << "{";
	for (int i = 0; i < (int)ss.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << "[" << ss[i].l << ", " << ss[i].r << ")";
	}
	ostr << "}";
	return ostr;
}

const int L = 19;
const int N = 1 << (L + 1);
int cnt[N + 1];

int main() {
	int n = nxt();
	vector<itn> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int bit = 0; bit < L; ++bit) {
		int mod = (2 << bit);
		Segs cur = {{0, mod}};
		for (int x : a) {
			x = ((x + N) & (mod - 1));
			int l = (mod - x) & (mod - 1);
			int r = (l + mod / 2) & (mod - 1);
			auto nw = getCyclic(l, r, mod);
			cur = intersect(cur, nw);
		}
		for (int i = 0; i < N; i += mod) {
			for (auto s : cur) {
				cnt[i + s.l] ^= (1 << bit);
				cnt[i + s.r] ^= (1 << bit);
			}
		}
		cnt[0] ^= (1 << bit);
		// cerr << cur << "\n";
	}

	for (int i = 1; i < N; ++i) {
		cnt[i] ^= cnt[i - 1];
	}

	for (int i = 0; i < N; ++i) {
		cnt[i] |= i;
	}

	int offset = 0;
	for (int i = 1; i < N; ++i) {
		if (__builtin_popcount(cnt[i]) < __builtin_popcount(cnt[offset])) {
			offset = i;
		}
	}

	printf("%d\n", __builtin_popcount(cnt[offset]));
	for (int bit = 1; bit <= cnt[offset]; bit <<= 1) {
		if (offset & bit) {
			printf("%d ", -bit);
		} else if (cnt[offset] & bit) {
			printf("%d ", bit);
		}
	}
	printf("\n");

	return 0;
}