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
10
a
aa
aaa
aaaa
abab
abcabc
abacaba
xxyy
xyyx
xyxy
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		string a;
		cin >> a;
		cout << (a.size() % 2 == 0 and a.substr(0, a.size() / 2) == a.substr(a.size() / 2) ? "YES" : "NO") << "\n";
	}

}