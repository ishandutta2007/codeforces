// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|      TEXHOKYOK 2017 OTOP 1     |
+----------------------------------+
|              3AAA C            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

inline bool sogl(char c) {
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

inline bool triple(char a, char b, char c) {
	return a == b && b == c;
}

inline bool bad(char a, char b, char c) {
	if (triple(a, b, c)) {
		return false;
	}
	if (sogl(a) && sogl(b) && sogl(c)) {
		return true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	string s; cin >> s;
	int n = s.size();
	vector< vector<char> > good(n, vector<char>(n, false));
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = i; j < n; j++) {
			if (j >= i+2 && bad(s[j], s[j-1], s[j-2])) {
				ok = false;
			}
			good[i][j] = ok;
		}
	}
	vector<int> dp(n), p(n);
	for (int i = 0; i < n; i++) {
		if (good[0][i]) {
			dp[i] = 0;
			p[i] = -1;
		} else {
			dp[i] = infinity;
			for (int j = 0; j < i; j++) {
				if (good[j+1][i] && dp[j]+1 < dp[i]) {
					dp[i] = dp[j]+1;
					p[i] = j;
				}
			}
		}
	}
	string res = "";
	int i = n-1;
	while (i >= 0) {
		res = " " + s.substr(p[i]+1, i-p[i]) + res;
		i = p[i];
	}
	res.erase(0, 1);
	cout << res << endl;
	return 0;
}