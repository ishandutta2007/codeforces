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

	int n = nxt();
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		int x1 = nxt(), y1 = nxt(), x2 = nxt(), y2 = nxt();
		if (x1 > x2) {
			swap(x1, x2);
		}
		if (y1 > y2) {
			swap(y1, y2);
		}
		x1 = abs(x1) % 2;
		y1 = abs(y1) % 2;
		printf("%d\n", x1 * 2 + y1 + 1);
	}

	return 0;
}