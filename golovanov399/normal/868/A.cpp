#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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
	string s;
	cin >> s;
	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == s) {
			puts("YES");
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][1] == s[0] && a[j][0] == s[1]) {
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");

	return 0;
}