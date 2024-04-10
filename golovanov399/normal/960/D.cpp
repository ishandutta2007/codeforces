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

const int L = 62;
long long level_size[L];
long long shift[L];

inline int getLevel(long long v) {
	return 63 - __builtin_clzll(v);
}

long long getVertex(long long val) {
	int level = getLevel(val);
	val = (val + shift[level]) % level_size[level] + level_size[level];
	return val;
}

long long getValue(long long node) {
	int level = getLevel(node);
	return level_size[level] + (node - shift[level]) % level_size[level];
}

void shiftAll(long long val, long long sh) {
	int level = getLevel(val);
	sh = (sh % level_size[level] + level_size[level]) % level_size[level];

	while (level < L) {
		shift[level] = (shift[level] + sh) % level_size[level];
		sh *= 2;
		++level;
	}
}

void shiftLevel(long long val, long long sh) {
	int level = getLevel(val);
	sh = (sh % level_size[level] + level_size[level]) % level_size[level];

	shift[level] = (shift[level] + sh) % level_size[level];
}

int main() {
	for (int i = 0; i < L; ++i) {
		level_size[i] = (1ll << i);
		shift[i] = 0;
	}
	int q = nxt();
	while (q--) {
		int t = nxt();
		if (t < 3) {
			long long x, k;
			scanf("%lld%lld", &x, &k);
			if (t == 1) {
				shiftLevel(x, k);
			} else {
				shiftAll(x, k);
			}
		} else {
			long long x;
			scanf("%lld", &x);

			long long v = getVertex(x);
			while (v > 0) {
				printf("%lld ", getValue(v));
				v /= 2;
			}
			printf("\n");
		}
	}

	return 0;
}