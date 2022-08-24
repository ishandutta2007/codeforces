#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

const int mod = 1000000007;
const int init = 1 << 30;

long long getSum(int x, int y, int sz) {
	long long res = 0;
	for (int i = 1; i < sz; i <<= 1) {
		int x1 = (x & (i + i - 1));
		int y1 = (y & (i + i - 1));
		res += ((1ll * x * y - 1ll * x1 * y1) / 2 % mod + (1ll * min(x1, i) * max(0, y1 - i) + 1ll * min(y1, i) * max(0, x1 - i)) % mod) * i % mod;
	}
	return res % mod;
}

pair<long long, long long> f(int x, int y, int k, int sz = init) {
	if (x < 0 || y < 0 || k < 0) {
		return {0, 0};
	}
	x = min(x, sz);
	y = min(y, sz);
	k = min(k, sz - 1);

	if (sz == x && sz == y) {
		return {1ll * k * (k + 1) / 2 % mod * sz % mod, 1ll * (k + 1) * sz % mod};
	}

	if (k == sz - 1) {
		return {getSum(x, y, sz), 1ll * x * y % mod};
	}

	int nx = sz / 2;
	auto p00 = f(x, y, k, nx);
	auto p01 = f(x, y - nx, k - nx, nx);
	auto p10 = f(x - nx, y, k - nx, nx);
	auto p11 = f(x - nx, y - nx, k, nx);
	pair<long long, long long> ret = {0, 0};
	ret.first = p00.first + p01.first + p10.first + p11.first;
	ret.second = (p00.second + p01.second + p10.second + p11.second) % mod;
	ret.first += 1ll * nx * (p01.second + p10.second) % mod;
	ret.first %= mod;
	return ret;
}

long long g(int x, int y, int k) {
	auto p = f(x, y, k);
	return (p.first + p.second) % mod;
}

int getAns(int x1, int y1, int x2, int y2, int k) {
	long long res = g(x2, y2, k) - g(x1, y2, k) - g(x2, y1, k) + g(x1, y1, k);
	res %= mod;
	if (res < 0) {
		res += mod;
	}
	return res;
}

int main(){
	int q = nxt();
	while (q--) {
		int x1 = nxt() - 1, y1 = nxt() - 1, x2 = nxt(), y2 = nxt(), k = nxt() - 1;
		printf("%d\n", getAns(x1, y1, x2, y2, k));
	}

	return 0;
}