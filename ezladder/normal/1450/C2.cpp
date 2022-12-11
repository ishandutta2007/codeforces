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
int cnt[2][3];

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

		for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) cnt[i][j] = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int c = (i + j) % 3;
				if (a[i][j] == 'X') cnt[0][c]++;
				if (a[i][j] == 'O') cnt[1][c]++;
			}
		}

		int ii = 0, jj = 1;

		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (i != j) {
		//	cout << i << ' ' << j << ' ' << cnt[0][i] << ' ' << cnt[1][j] << endl;
			if (cnt[0][ii] + cnt[1][jj] > cnt[0][i] + cnt[1][j]) {
				ii = i;
				jj = j;
			}
		}

//		cout << ii << ' ' << jj << ' ' << cnt[0][ii] << ' ' << cnt[1][jj] << endl;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int c = (i + j) % 3;
				if (c == ii) if (a[i][j] == 'X') a[i][j] = 'O';
				if (c == jj) if (a[i][j] == 'O') a[i][j] = 'X';
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