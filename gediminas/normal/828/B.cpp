/*input
3 3
WWW
WWW
WWW

*/
#include <bits/stdc++.h>

using namespace std;
template<class T, class Y>
void maxch(T &x, const Y &y) {
	if (x < y)
		x = y;
}
template<class T, class Y>
void minch(T &x, const Y &y) {
	if (x > y)
		x = y;
}

int main () {
	int n, m;
	cin >> n >> m;
	bool matr[n][m];
	int minx = n, maxx = 0, miny = m, maxy = 0;
	int kiek = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			matr[i][j] = x == 'B';

			if (matr[i][j]) {
				maxch(maxx, i);
				minch(minx, i);
				maxch(maxy, j);
				minch(miny, j);
				kiek++;
			}
		}
	}

	if (kiek == 0) {
		cout << 1 << endl;
		return 0;
	}

	int kras = max(maxx - minx, maxy - miny) + 1;

	if (n >= kras and m >= kras)
		cout << kras *kras - kiek << endl;
	else
		cout << -1;



	return 0;
}