/*input
aba
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a;
	cin >> a;
	cout << a;
	reverse(a.begin(), a.end());
	cout << a;


	return 0;
}