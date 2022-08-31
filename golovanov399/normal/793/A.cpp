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

int main(){
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int rem = a[0] % k;
	for (int x : a) {
		if (x % k != rem) {
			puts("-1");
			return 0;
		}
	}

	long long ans = 0;
	int mn = *min_element(all(a));
	for (int x : a) {
		ans += (x - mn) / k;
	}

	cout << ans << "\n";

	return 0;
}