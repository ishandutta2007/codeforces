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

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	sort(all(a));

	vector<int> deg(n);
	deg[0] = 1;
	for (int i = 1; i < n; ++i) {
		deg[i] = (deg[i - 1] * 2) % mod;
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = (deg[i] - deg[n - 1 - i] + mod) % mod;
		ans += 1ll * tmp * a[i] % mod;
	}

	cout << ans % mod << "\n";

	return 0;
}