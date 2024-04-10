#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 410, INF = 1e9;
int t, n, m;
int a[nax][nax], b[nax][nax];

int sum(int x1, int y1, int x2, int y2) {
	return b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
}

int sum2(int x1, int y1, int x2, int y2) {
	return (x2 - x1 + 1) * (y2 - y1 + 1) - sum(x1,y1,x2,y2);
}

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			for(int j = 0; j < m; ++j) {
				a[i][j + 1] = s[j] - '0';
			}
			for(int j = 1; j <= m; ++j) {
				b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
			}
		}
		int ans = INF;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 4; j <= n; ++j) {
				int sofar = INF;
				for(int k = 4; k <= m; ++k) {
					//cout << i << " " << j << " " << k << "\n";
					int cost = sum2(i + 1, k - 3, j - 1, k - 3);
					cost = cost - sum2(i, 1, i, k - 3);
					cost = cost - sum2(j, 1, j, k - 3);
					cost = cost - sum(i + 1, 1, j - 1, k - 3);
					//cout << cost << "\n";
					sofar = min(sofar, cost);
					int cur = sum2(i + 1, k, j - 1, k);
					cur = cur + sum2(i, 1, i, k - 1) + sum2(j, 1, j, k - 1) + sum(i + 1, 1, j - 1, k - 1);
					ans = min(ans, cur + sofar);
				}
			}
		}
		cout << ans << "\n";
	}
	
}