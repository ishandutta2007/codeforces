#include <bits/stdc++.h>

using namespace std;
/*input
11
aaaaBaabAbA
*/
/*input
12
zACaAbbaazzC
*/
/*input
3
ABC
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	string a;
	cin >> n >> a;
	map<char, int> c;
	int i = 0, j = 0;
	int ans = 0;

	while (j < a.size()) {
		if (isupper(a[j])) {
			j++;
			c.clear();
			i = j;
			continue;
		}

		c[a[j]]++;
		j++;
		ans = max(ans, (int)c.size());
	}

	cout << ans;
}