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
const int N = 1111111;
itn deg[N];

int main(){
	deg[0] = 1;
	for (int i = 1; i < N; ++i) {
		deg[i] = deg[i - 1] * 2 % mod;
	}

	string s;
	cin >> s;
	int cnt = 0;
	long long ans = 0;
	for (char c : s) {
		if (c == 'a') {
			cnt += 1;
		} else {
			ans += deg[cnt] - 1;
		}
	}

	cout << ans % mod << "\n";

	return 0;
}