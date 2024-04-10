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

const int L = 21;
const int N = 1 << L;
bool fft_initialized = false;

using ld = long double;
using base = complex<ld>;
using Poly = vector<long long>;

const ld pi = acosl(-1);
base angles[N + 1];
int bitrev[N];

// don't know why such eps, may be changed
const ld eps = 1e-7;

inline bool eq(ld x, ld y) {
	return abs(x - y) < eps;
}

void fft_init() {
	for (int i = 0; i <= N; ++i) {
		angles[i] = {cosl(2 * pi * i / N), sinl(2 * pi * i / N)};
	}

	for (int i = 0; i < N; ++i) {
		int x = i;
		for (int j = 0; j < L; ++j) {
			bitrev[i] = (bitrev[i] << 1) | (x & 1);
			x >>= 1;
		}
	}

	fft_initialized = true;
}

inline int revBit(int x, int len) {
	return bitrev[x] >> (L - len);
}

void fft(vector<base>& a, bool inverse = false) {
	assert(fft_initialized && "you fucking cunt just write fft_init()");
	int n = a.size();
	assert(!(n & (n - 1)));	// work only with powers of two
	int l = __builtin_ctz(n);

	for (int i = 0; i < n; ++i) {
		int j = revBit(i, l);
		if (i < j) {
			swap(a[i], a[j]);
		}
	}

	for (int len = 1; len < n; len *= 2) {
		for (int start = 0; start < n; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				base x = a[start + i], y = a[start + len + i];
				int idx = N / 2 / len * i;
				base w = y * angles[inverse ? N - idx : idx];
				a[start + i] = x + w;
				a[start + len + i] = x - w;
			}
		}
	}

	if (inverse) {
		for (auto& x : a) {
			x /= n;
		}
	}
}

Poly multiply(Poly a, Poly b) {
	int n = 1;
	while (n < (int)a.size() || n < (int)b.size()) {
		n *= 2;
	}
	vector<base> ar(n + n), br(n + n);
	for (int i = 0; i < (int)a.size(); ++i) {
		ar[i] = a[i];
	}
	for (int i = 0; i < (int)b.size(); ++i) {
		br[i] = b[i];
	}
	fft(ar);
	fft(br);
	for (int i = 0; i < n + n; ++i) {
		ar[i] = ar[i] * br[i];
	}
	fft(ar, true);
	a.resize(ar.size());
	for (int i = 0; i < (int)a.size(); ++i) {
		a[i] = roundl(real(ar[i]));
	}
	return a;
}

const int wow6 = 216 * 6;
const int wow3 = 729 * 9;

Poly q;
int cnt[wow3][wow6];
const vector<int> cc[6] = {{0}, {1}, {2}, {0, 1}, {0, 2}, {1, 2}};

void rec(int l, int r, int rest, int suf, int rm3, int idx) {
	if (rest == 0) {
		cnt[l][idx] += q[l * rm3 + suf];
		return;
	}
	int x = r % 6;
	r /= 6;
	for (int y : cc[x]) {
		rec(l, r, rest - 1, suf + y * rm3, rm3 * 3, idx);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fft_init();

	int w = nxt(), n = nxt(), m = nxt();
	int tp = 1;
	for (int i = 0; i < w; ++i) {
		tp *= 3;
	}
	q.assign(tp, 0);
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		int y = 0;
		for (int i = 0, j = 1; i < w; ++i, j *= 3) {
			y += x % 2 * j;
			x >>= 1;
		}
		q[y] += 1;
	}

	q = multiply(q, q);

	int rm = min(w / 2, 4);
	int lm = w - rm;
	int lm3 = 1;
	for (int i = 0; i < lm; ++i) {
		lm3 *= 3;
	}
	int rm6 = 1;
	for (int i = 0; i < rm; ++i) {
		rm6 *= 6;
	}
	for (int l = 0; l < lm3; ++l) {
		for (int r = 0; r < rm6; ++r) {
			rec(l, r, rm, 0, 1, r);
		}
	}

	vector<vector<int>> possibilities(256);
	possibilities['A'] = {0, 1};
	possibilities['a'] = {2};
	possibilities['O'] = {0};
	possibilities['o'] = {1, 2};
	possibilities['X'] = {0, 2};
	possibilities['x'] = {1};

	while (m--) {
		string s;
		cin >> s;
		vector<vector<int>> poss(w);
		for (int i = 0; i < (int)s.length(); ++i) {
			poss[i] = possibilities[s[i]];
		}

		int r = 0;
		for (int i = lm; i < w; ++i) {
			int x = ((int)poss[i].size() == 1) ? poss[i][0] : poss[i][0] + poss[i][1] + 2;
			r = r * 6 + x;
		}

		int max_mask = 0;
		for (int i = 0; i < lm; ++i) {
			max_mask = (max_mask * 2) + (int)poss[i].size() - 1;
		}

		int ans = 0;
		for (int mask = max_mask; mask >= 0; mask = (mask - 1) & max_mask) {
			int l = 0;
			for (int i = 0; i < lm; ++i) {
				l = l * 3 + poss[i][(mask >> (lm - 1 - i)) & 1];
			}

			ans += cnt[l][r];

			if (mask == 0) {
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}