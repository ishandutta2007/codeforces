#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll cc[55][55];

int main(){
#ifdef LOCAL
	// freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 55; ++i) {
		cc[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1];
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int dd = i + j;
			if (i % 2 == 0) {
				cout << "0 ";
			} else {
				cout << ((ll)1 << dd) << ' ';
			}
		}
		cout << endl;
	}

	int q;
	cin >> q;
	while (q--) {
		ll val = 0;
		cin >> val;
		int x = 1, y = 1;
		cout << "1 1" << endl;
		while (min(x, y) != n) {
			if (x == n) {
				++y;
			} else if (y == n) {
				++x;
			} else {
				int nxt = x + y + 1 - 2;
				if ((val >> nxt) & 1) {
					if (x % 2 == 0) ++y;
					else ++x;
				} else {
					if (x % 2 == 0) ++x;
					else ++y;
				}
			}
			cout << x << ' ' << y << endl;
		}
	}

}