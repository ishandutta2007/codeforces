/*input
7
add 3
add 2
add 1
remove
add 4
remove
remove
remove
add 6
add 7
add 5
remove
remove
remove

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	deque<int> a;
	int p = 1;
	int ats = 0;

	for (int i = 0; i < 2 * n; i++) {
		string x;
		cin >> x;

		if (x[0] == 'a') {
			int y;
			cin >> y;
			a.push_back(y);
		}
		else {
			if (a.size() == 0) {
				p++;
				continue;
			}
			else if (a.back() == p++)
				a.pop_back();
			else {
				ats++;
				a.clear();
			}
		}
	}

	cout << ats;

	return 0;
}