#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1 && m == 1) {
		cout << "YES" << nl;
		cout << 1 << nl;
		return 0;
	}

	bool transpose = false;
	int tr[n*m];
	if (m < n) {
		transpose = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tr[j*n+i] = i*m+j;
			}
		}
		swap(m,n);
	}

	int grid[n][m];

	if (n == 1 && m < 4) {
		cout << "NO" << nl;
		return 0;
	} else if (n == 2 && m < 4) {
		cout << "NO" << nl;
		return 0;
	} else if (n == 3 && m == 3) {
		cout << "YES" << nl;
		grid[0][0] = 5-1;
		grid[0][1] = 7-1;
		grid[0][2] = 2-1;
		grid[1][0] = 9-1;
		grid[1][1] = 1-1;
		grid[1][2] = 6-1;
		grid[2][0] = 4-1;
		grid[2][1] = 3-1;
		grid[2][2] = 8-1;
	}
	
	else {
		cout << "YES" << nl;
		if (m % 2 == 0) {
			for (int i = 0; i < n; i++) {
				int j = (i % 2) ? 0 : m-1;
				int d = (i % 2) ? 1 : -1;
				for (int k = 1; k < m; k += 2) {
					grid[i][j] = i*m + k;
					j += d;
				}
				for (int k = 0; k < m; k += 2) {
					grid[i][j] = i*m + k;
					j += d;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				int j = 0;
				for (int k = (i % 2) ? 0 : 1; k < m; k += 2)
					grid[i][j++] = i*m + k;
				for (int k = (i % 2) ? 1 : 0; k < m; k += 2)
					grid[i][j++] = i*m + k;
			}
		}
	}

	if (transpose) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++)
				cout << tr[grid[i][j]]+1 << " ";
			cout << nl;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << grid[i][j]+1 << " ";
			cout << nl;
		}
	}

	return 0;
}