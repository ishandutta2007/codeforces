#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
6
5
zx
ab
cc
zx
ba
2
ab
bad
4
co
def
orc
es
3
a
b
c
3
ab
cd
cba
2
ab
ab
*/

string reversed(string a) {
	reverse(a.begin(), a.end());
	return a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		bool ok = false;

		set<string> yr;
		set<string> yrbe;

		for (int i = 0; i < n; ++i) {
			string a;
			cin >> a;

			if (ok) {
				continue;
			}

			string b = reversed(a);
			yr.insert(a);

			if (yr.count(b)) {
				ok = true;
				continue;
			}

			if (a.size() == 3) {
				yrbe.insert(a.substr(0, 2));
				string t = "";
				t.push_back(a[2]);
				t.push_back(a[1]);

				if (yr.count(t)) {
					ok = true;
					continue;
				}
			}
			else {
				if (yrbe.count(b)) {
					ok = true;
					continue;
				}
			}
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}