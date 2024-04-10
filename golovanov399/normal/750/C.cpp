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

void panic() {
	puts("Impossible");
	exit(0);
}

int main(){

	int n = nxt();
	int mx = INT_MIN, mn = INT_MAX;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int c = nxt(), d = nxt();
		if (d == 1) {
			mn = min(mn, cur);
		} else {
			mx = max(mx, cur);
		}
		cur += c;
	}

	if (mx >= mn) {
		panic();
	} else if (mx == INT_MIN) {
		puts("Infinity");
	} else {
		cout << 1899 + cur - mx << "\n";
	}

	return 0;
}