// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|      TEXHOKYOK 2017 OTOP 1     |
+----------------------------------+
|              3AAA D            |
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

signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<string> v(n);
	map<string, int> matches;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		set<string> substrs;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k + j < 9; k++) {
				substrs.insert(v[i].substr(k, j+1));
			}
		}
		for (const auto &it : substrs) {
			matches[it]++;
		}
	}
	for (int i = 0; i < n; i++) {
		string ans = "";
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k + j < 9; k++) {
				string ss = v[i].substr(k, j+1);
				if (matches[ss] == 1) {
					ans = ss;
					break;
				}
			}
			if (ans != "") {
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}