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
	int n = nxt(), t = nxt(), k = nxt(), d = nxt();
	n = (n + k - 1) / k;
	int t1 = t * n;
	if (d >= t1 - t) {
		puts("NO");
	} else {
		puts("YES");
	}

	return 0;
}