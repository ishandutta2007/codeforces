/*input
4
2 5 3 1
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main () {
	long n;
	cin >> n;
	long mas[n];

	for (long i = 0; i < n; i++)
		cin >> mas[i];

	cout << ((*max_element(mas,mas+n)) xor mas[n-1]);

	return 0;
}