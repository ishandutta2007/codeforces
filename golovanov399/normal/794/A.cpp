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

int main() {
	int a = nxt(), b = nxt(), c = nxt();
	int cnt = 0;
	int n = nxt();
	while (n--) {
		int x = nxt();
		if (x > b && x < c) {
			++cnt;
		}
	}

	printf("%d\n", cnt);

	return 0;
}