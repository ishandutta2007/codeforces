#include <bits/stdc++.h>

using namespace std;
/*input
4
1 2 4 4
*/
/*input
9
1 1 8 8 8 4 4 4 4
*/
/*input
7
4 3 7 1 4 3 3
*/
int main () {
	int n;
	cin >> n;
	map<int, int> a;
	set<int> aa;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
		aa.insert(x);
		aa.insert(x + 1);
		aa.insert(x - 1);
	}

	map<int, int> b = a;
	set<int> ma;

	for (int t : aa) {
		if (!ma.count(t - 1) and a[t]) {
			a[t]--;
			ma.insert(t - 1);
		}

		if (!ma.count(t) and a[t]) {
			a[t]--;
			ma.insert(t);
		}

		if (!ma.count(t + 1) and a[t]) {
			a[t]--;
			ma.insert(t + 1);
		}
	}

	set<int> mi;
	a = b;

	for (int t : aa) {
		if (!a[t]) {
			continue;
		}

		if (mi.count(t - 1) or mi.count(t)) {
			a[t] = 0;
		}
		else {
			a[t] = 0;
			mi.insert(t + 1);
		}
	}

	cout << mi.size() << " " << ma.size() << endl;
}