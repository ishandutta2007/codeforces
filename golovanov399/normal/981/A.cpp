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

bool isPal(const string& s) {
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] != s[(int)s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int l = 1; l <= (int)s.length(); ++l) {
		for (int i = 0; i + l <= (int)s.length(); ++i) {
			if (!isPal(s.substr(i, l))) {
				ans = max(ans, l);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}