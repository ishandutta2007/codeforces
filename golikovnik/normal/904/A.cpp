#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
#define X first
#define Y second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int v1, v2, v3, vm;
	cin >> v1 >> v2 >> v3 >> vm;
	for (int a = 1; a <= 300; ++a) {
		for (int b = a + 1; b <= 300; ++b) {
			for (int c = b + 1; c <= 300; ++c) {
				if (2 * v1 >= c && 2 * v2 >= b && 2 * v3 >= a && v1 <= c && v2 <= b && v3 <= a && vm <= c && vm <= b && vm <= a && 2 * vm >= a && 2 * vm < b && 2 * vm < c) {
					cout << c << endl << b << endl << a << endl;
					return 0;
				}
			}
		}
	}	
	cout << -1 << endl;
	return 0;
}