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
	int n = nxt();
	vector<int> a = {0};
	for (int i = 1;; ++i) {
		a.push_back(i * (i - 1) / 2);
		if (a[i] >= n) {
			break;
		}
	}
	vector<int> cnt;
	for (int i = (int)a.size() - 1; i >= 2;) {
		if (a[i] > n) {
			--i;
		} else {
			n -= a[i];
			cnt.push_back(i);
		}
	}

	assert(cnt.size() <= 26);
	string s;
	for (int i = 0; i < (int)cnt.size(); ++i) {
		s += string(cnt[i], 'a' + i);
	}
	if (s == "") {
		s = "a";
	}
	cout << s << "\n";

	return 0;
}