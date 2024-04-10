#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		cnt += (c[i] == c[i + 1]);
	cout << cnt;
	return 0;
}