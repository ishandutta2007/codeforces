#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 107;

char a[MAXN][MAXN];
int n, m;

bool check(int l1, int r1, int l2, int r2, int c){
	for (int i = l1; i <= r1; ++i){
		for (int j = l2; j <= r2; ++j){
			if (a[i][j] != c){
				return false;
			}
		}
	}

	return true;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	char c1 = 'A', c2 = 'A', c3 = 'A';
	int k;
	if (!(n % 3)){
		k = n / 3;
		if (check(0, k - 1, 0, m - 1, 'R')){
			c1 = 'R';
		}

		if (check(0, k - 1, 0, m - 1, 'B')){
			c1 = 'B';
		}

		if (check(0, k - 1, 0, m - 1, 'G')){
			c1 = 'G';
		}


		if (check(k, 2 * k - 1, 0, m - 1, 'R')){
			c2 = 'R';
		}

		if (check(k, 2 * k - 1, 0, m - 1, 'B')){
			c2 = 'B';
		}

		if (check(k, 2 * k - 1, 0, m - 1, 'G')){
			c2 = 'G';
		}


		if (check(2 * k, 3 * k - 1, 0, m - 1, 'R')){
			c3 = 'R';
		}

		if (check(2 * k, 3 * k - 1, 0, m - 1, 'B')){
			c3 = 'B';
		}

		if (check(2 * k, 3 * k - 1, 0, m - 1, 'G')){
			c3 = 'G';
		}

		if ((c1 == 'R' || c2 == 'R' || c3 == 'R') && (c1 == 'B' || c2 == 'B' || c3 == 'B') && (c1 == 'G' || c2 == 'G' || c3 == 'G')){
			cout << "YES\n";
			return 0;
		}
	}



	if (!(m % 3)){
		k = m / 3;
		if (check(0, n - 1, 0, k - 1, 'R')){
			c1 = 'R';
		}

		if (check(0, n - 1, 0, k - 1, 'B')){
			c1 = 'B';
		}

		if (check(0, n - 1, 0, k - 1, 'G')){
			c1 = 'G';
		}


		if (check(0, n - 1, k, 2 * k - 1, 'R')){
			c2 = 'R';
		}

		if (check(0, n - 1, k, 2 * k - 1, 'B')){
			c2 = 'B';
		}

		if (check(0, n - 1, k, 2 * k - 1, 'G')){
			c2 = 'G';
		}


		if (check(0, n - 1, 2 * k, m - 1, 'R')){
			c3 = 'R';
		}

		if (check(0, n - 1, 2 * k, m - 1, 'B')){
			c3 = 'B';
		}

		if (check(0, n - 1, 2 * k, m - 1, 'G')){
			c3 = 'G';
		}

		if ((c1 == 'R' || c2 == 'R' || c3 == 'R') && (c1 == 'B' || c2 == 'B' || c3 == 'B') && (c1 == 'G' || c2 == 'G' || c3 == 'G')){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}