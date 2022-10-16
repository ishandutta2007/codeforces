#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "../includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

//CF_LINK: https://codeforces.com/contest/1721/problem/A
/*input
5
rb
br
cc
wb
aa
aa
ab
cd
yy
xx
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;
	debug(TESTS);

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		string a, b;
		cin >> a >> b;
		debug(a, b);
		map<char, int> t;
		t[a[0]]++;
		t[a[1]]++;
		t[b[0]]++;
		t[b[1]]++;

		sort(a.begin(), a.end());

		if (t.size() == 1) {
			cout << "0\n";
		}
		else if (t.size() == 4) {
			cout << "3\n";
		}
		else if (t.size() == 2) {
			cout << "1\n";
		}
		else if (t.size() == 3) {
			cout << "2\n";
		}
	}
}