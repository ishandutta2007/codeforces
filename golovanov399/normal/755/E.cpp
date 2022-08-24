#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

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
	if (n == 2) {
		puts("-1");
		return 0;
	}
	if (k == 2) {
		if (n <= 4) {
			puts("-1");
			return 0;
		}
		printf("%d\n", n - 1);
		for (int i = 0; i < n - 1; ++i) {
			printf("%d %d\n", i + 1, i + 2);
		}
	} else if (k == 3) {
		if (n < 4) {
			puts("-1");
			return 0;
		}
		printf("%d\n", 2 + n - 3);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 2, 3);
		for (int i = 0; i < n - 3; ++i) {
			printf("%d %d\n", 3, 4 + i);
		}
	} else {
		puts("-1");
	}

	return 0;
}