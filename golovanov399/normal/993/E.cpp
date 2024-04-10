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

const int L = 20;
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

int main() {
	fft_init();

	int n = nxt(), x = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (nxt() < x);
	}

	vector<long long> b;
	int cur = 1;
	for (int x : a) {
		if (x) {
			b.push_back(cur);
			cur = 1;
		} else {
			++cur;
		}
	}
	b.push_back(cur);

	auto c = b;
	reverse(all(c));

	auto p = multiply(b, c);
	vector<long long> ans(n + 1, 0);
	for (int i = 1; i < (int)b.size(); ++i) {
		ans[i] = p[(int)b.size() - 1 - i];
	}
	for (auto x : b) {
		ans[0] += x * (x - 1) / 2;
	}

	for (auto x : ans) {
		printf("%lld ", x);
	}
	printf("\n");

	return 0;
}