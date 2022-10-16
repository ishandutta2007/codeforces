#include <bits/stdc++.h>

using namespace std;
/*input
5 2
#G#T#
*/
/*input
6 1
T....G
*/
/*input
7 3
T..#..G
*/
/*input
6 2
..GT..
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	int a = s.find('T');
	int b = s.find('G');

	if (a > b) {
		swap(a, b);
	}

	while (a <= b) {
		if (a == b) {
			cout << "YES";
			exit(0);
		}

		if (s[a] == '#') {
			break;
		}

		a += k;
	}

	cout << "NO";

}