#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
char a[333][333];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		int cnt[3] = {0, 0, 0};

		for (int c = 0; c < 3; ++c) {
			for (int i = 0; i < n; ++i) {
				int d = (c + i) % 3;
				for (int j = 0; j < n; ++j) {
					if (j % 3 == d && a[i][j] == 'X') ++cnt[c];
				}
			}
		}

		int v = 0;
		if (cnt[v] > cnt[1]) v = 1;
		if (cnt[v] > cnt[2]) v = 2;

		for (int i = 0; i < n; ++i) {
			int d = (v + i) % 3;
			for (int j = 0; j < n; ++j) {
				if (j % 3 == d && a[i][j] == 'X') a[i][j] = 'O';
			}
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << a[i][j];
			}
			cout << "\n";
		}

	}

}