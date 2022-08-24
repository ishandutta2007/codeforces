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

bool isVowel(char c) {
	return c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i';
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<pair<int, int>> dp(n + 1, make_pair(100000, -1));
	dp[0] = {0, 0};
	for (int i = 0; i < n; ++i) {
		int mask = 0;
		int cnt = 0;
		for (int j = i; j >= 0; --j) {
			if (isVowel(s[j])) {
				mask = cnt = 0;
			} else {
				mask |= (1 << (s[j] - 'a'));
				cnt += 1;
				if (cnt >= 3 && __builtin_popcount(mask) > 1) {
					break;
				}
			}
			pair<int, int> tmp = {dp[j].first, j};
			if (j) {
				tmp.first += 1;
			}
			dp[i + 1] = min(dp[i + 1], tmp);
		}
	}

	string res = "";
	int cur = dp[n].second;
	for (int i = n - 1; i >= 0; --i) {
		res += s[i];
		if (i == cur && i) {
			res += " ";
			cur = dp[cur].second;
		}
	}

	reverse(all(res));
	cout << res << "\n";

	return 0;
}