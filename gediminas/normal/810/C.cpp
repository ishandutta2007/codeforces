/*input
3
4 3 1
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#define modul 1000000007

int main () {
	int n;
	cin >> n;
	long long mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	long long sum = 0;
	long long dvej[n + 2];
	dvej[0] = 1;

	for (int i = 1; i <= n + 1; i++) {
		dvej[i] = dvej[i - 1] << 1;
		dvej[i] %= modul;
	}

	sort(mas, mas + n);

	for (int i = 0; i < n; i++) {
		sum -= (mas[i] * dvej[n - 1 - i]) % modul;
		sum %= modul;
		sum += (mas[i] * dvej[i]) % modul;
		sum %= modul;
	}

	cout << (sum + modul) % modul;

	return 0;
}