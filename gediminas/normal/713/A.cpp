#include <bits/stdc++.h>

using namespace std;

/*link https://codeforces.com/group/nIDHK2OChY/contest/254401/problem/D */
/*input
12
+ 1
+ 241
? 1
+ 361
- 241
? 0101
+ 101
? 101
- 101
? 101
+ 4000
? 0
*/
/*output
2
1
2
1
1
*/
/*input
4
+ 200
+ 200
- 200
? 0
*/
/*output
1
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	map<string, int> a;

	for (int i = 0; i < n; i++) {
		char t;
		string x;
		cin >> t >> x;

		while (x.size() < 18) {
			x = "0" + x;
		}

		for (auto && j : x) {
			j = j % 2;
		}

		if (t == '+') {
			a[x]++;
		}
		else if (t == '-')
			a[x]--;
		else {
			cout << a[x] << "\n";
		}
	}

}