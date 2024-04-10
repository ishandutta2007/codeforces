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
7
abacaba
abc
cccba
acb
dbsic
bac
abracadabra
abc
dddddddddddd
cba
bbc
abc
ac
abc
*/

bool contains(string a, string b) {
	if (!is_sorted(b.begin(), b.end())) {
		return false;
	}

	int j = 0;

	for (int i = 0; i < a.size() and j < b.size(); ++i) {
		if (a[i] == b[j]) {
			j++;
		}
	}

	return j == b.size();
}

string all(string a) {
	string b;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] <= 'c') {
			continue;
		}

		if (b.empty() || b.back() != a[i]) {
			b.push_back(a[i]);
		}
	}

	return b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;
		sort(a.begin(), a.end());

		if (!contains(a, b)) {
			cout << a << "\n";
			continue;
		}

		b += all(a);
		debug(all(a), b);
		
		swap(b[1], b[2]);

		map<char, int> t;

		for (int i = 0; i < b.size(); ++i) {
			t[b[i]] = i;
		}

		sort(a.begin(), a.end(), [&](char a, char b) -> bool {
			return t[a] < t[b];
		});
		cout << a << "\n";
	}

}