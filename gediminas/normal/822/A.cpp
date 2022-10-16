/*input
4 3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long a,b;
	cin >> a >> b;
	a=min(a,b);
	long long fak = 1;
	for(int i = 1; i <= a; i++) {
		fak*=i;
	}
	cout << fak;

	return 0;
}