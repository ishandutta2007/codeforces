/*input
2

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n;
	cin >> n;
	long long ats = n / 2;

	if (n % 2 == 1)
		ats -= n;

	cout << ats;


	return 0;
}