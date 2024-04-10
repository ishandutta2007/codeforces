#include <bits/stdc++.h>

using namespace std;
int nel = 0;
int n;
int ans = 1;

int read(int i) {
	int x;
	cin >> x;
	nel += x % 2;
	return ((n - 1 - i) && read(i + 1), ans +=
	((1 - __builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount((nel - 1) + (1 - x % 2))))))) + (1 - __builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount((n - 1 - nel) + (x % 2)))))))) * i);
}

/*input
5
2 4 7 8 10
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	read(0);
	cout << ans;
}