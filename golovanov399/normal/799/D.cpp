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

inline int ceil(int a, int b) {
	return (a + b - 1) / b;
}

const int N = 111111;
char can[N];

const long long INF = 1e13;

#define lg kjaklf

struct Long {
	long long a, b;

	Long(long long x) {
		a = 0;
		b = x;
	}

	Long(long long _a, long long _b): a(_a), b(_b) {}

	void operator *=(long long x) {
		b *= x;
		a += b / INF;
		b %= INF;
	}

	Long operator *(long long x) {
		long long aa = a, bb = b;
		bb *= x;
		aa += bb / INF;
		bb %= INF;
		return Long(aa, bb);
	}

	bool operator <(const Long& lg) const {
		return make_pair(a, b) < make_pair(lg.a, lg.b);
	}
};

int solve(int a, int b, const vector<int>& c) {
	int n = c.size();
	memset(can, 0, (a + 1) * sizeof(char));
	vector<int> tmp = {1};
	can[1] = 1;
	long long mn = 1;
	Long cur = 1;
	for (int i = 0; i < n; ++i) {
		if (mn >= a && !(cur < Long(mn) * b)) {
			return i;
		}
		int x = c[i];
		for (int j = (int)tmp.size() - 1; j >= 0; --j) {
			long long t = 1ll * tmp[j] * x;
			if (t >= a) {
				if (mn < a || t < mn) {
					mn = t;
				}
			} else {
				if (!can[t]) {
					tmp.push_back(t);
					can[t] = 1;
				}
			}
		}
		cur *= x;
		if (mn < a) {
			mn *= x;
		}
	}
	if (mn >= a && !(cur < Long(mn) * b)) {
		return n;
	} else {
		return n + 1;
	}
}

bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int a = nxt(), b = nxt();
	int h = nxt(), w = nxt();
	int n = nxt();

	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = nxt();
	}
	sort(all(c));
	reverse(all(c));

	int ans = solve(ceil(a, h), ceil(b, w), c);
	swap(w, h);
	ans = min(ans, solve(ceil(a, h), ceil(b, w), c));
	if (ans == n + 1) {
		ans = -1;
	}

	cout << ans << "\n";

	return 0;
}