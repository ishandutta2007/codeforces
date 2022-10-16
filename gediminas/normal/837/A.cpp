#include <bits/stdc++.h>
using namespace std;

/*link https://codeforces.com/contest/837/problem/A */
/*input
7
NonZERO
*/
/*output
5
*/
/*input
24
this is zero answer text
*/
/*output
0
*/
/*input
24
Harbour Space University
*/
/*output
1
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ma = 0;
	int n;
	cin >> n;
	cin.ignore(10,'\n');
	cin >> noskipws;
	//test
	int z = 0;

	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;

		if (x == ' ') {
			z = 0;
		}
		else if (isupper(x))
			z++;

		ma = max(ma, z);
	}

	cout << ma;
}