#include <bits/stdc++.h>
using namespace std;

int main() {
	string year;
	cin >> year;
	int count = 0;
	for (int i = year.size()-1, d = 1; i > 0; i--, d *= 10) {
		count += d * (10 - year[i] + '0');
		year[i-1]++;
	}
	if (year.size() > 1)
		cout << count << endl;
	else
		cout << 1 << endl;
	return 0;
}