#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*input
7
babba
abaac
codeforces
zeroorez
abcdcba
bbbbbbb
a

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		string x;
		cin >> x;
		int keit = 0;

		for (int i = 0; i < (int)x.size(); ++i) {
			set<char> a;

			if (i >= 2) {
				a.insert(x[i - 2]);
			}

			if (i >= 1) {
				a.insert(x[i - 1]);
			}

			if (a.count(x[i])) {
				if (i + 1 < (int)x.size()) {
					a.insert(x[i + 1]);
				}

				if (i + 2 < (int)x.size()) {
					a.insert(x[i + 2]);
				}

				keit++;

				for (char j = 'a'; j <= 'z'; ++j) {
					if (!a.count(j)) {
						x[i] = j;
						break;
					}
				}
			}
		}

		cout << keit << "\n";
	}

}