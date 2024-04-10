#include <iostream>
#include <vector>

#define ll long long
#define forin(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i += 2) {
		if (a[i] == a[i + 1]) {
			cnt++;
			if (a[i] == 'a')
				a[i] = 'b';
			else
				a[i] = 'a';
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		cout << a[i];
	return 0;
}