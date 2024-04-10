#include <iostream>

using namespace std;

int s, i, n, mark[5000], been[2000][2000];

int main() {
	cin >> n;
	s = 1;
	for (i = 1; i <= n * n; ++i) {
		if (been[s][i % n] == 1)
			break;
		been[s][i % n] = 1, mark[s] = 1, s = (s + i - 1) % n + 1;
	}             
	for (i = 1; i <= n; ++i)
		if (mark[i] == 0) {
			cout << "NO\n";
			return 0;
		}

	cout << "YES\n";
}