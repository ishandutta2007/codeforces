#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;
int a[333][333];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

		int f = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int cnt = 0;
				for (int d = 0; d < 4; ++d) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (min(nx, ny) < 0 || nx >= n || ny >= m) {

					} else {
						++cnt;
					}
				}
				if (cnt < a[i][j]) {
					f = 1;
				} else {
					a[i][j] = cnt;
					
				}
			}
		}

		if (f) cout << "NO\n"; else cout << "YES\n";
		if (!f) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cout << a[i][j] << ' ';
				}
				cout << "\n";
			}
		}
	}

}