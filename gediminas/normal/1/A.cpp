/*input
6 6 4
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long a,b,c;
	cin >> a >> b >> c;
	cout << (a/c+(a%c>0))*(b/c+(b%c>0)) << endl;


	return 0;
}