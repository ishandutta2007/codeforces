/*input
3 3 1 2
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

int main () {
	long n;
	cin >> n;
	long mas[n];

	for (long i = 0; i < n; i++)
		cin >> mas[i];
		
	for (long i = 0; i < 20000000ll; i++){
	    int *j = new int[2];
	    delete[] j;
	}
	sort(mas, mas + n);

	for (long i = 0; i < n - 1; i++)
		cout << mas[i] << " ";

	cout << mas[n - 1];

	return 0;
}