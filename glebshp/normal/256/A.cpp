#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 5 * 1000;

int n;

int seq[size];
int len[size], prv[size], nx[size];
map <int, int> allnum;
int f[size][size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> n;

	if (n == 1) {
		cout << '1' << endl;

		return 0;
	}
	int ans = 2;

	for (int i = 0; i < n; i++)
		nx[i] = -1;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		if (allnum.find(seq[i]) == allnum.end()) {
			allnum[seq[i]] = i;
			len[i] = 1;
			prv[i] = -1;
		} else {
			nx[allnum[seq[i]]] = i;
			prv[i] = allnum[seq[i]];
			len[i] = len[prv[i]] + 1;
			ans = max(ans, len[i]);
			allnum[seq[i]] = i;
		}
	}

	for (int i = 1; i < n; i++)
		for (int j = i - 1; j >= 0; j--) {
			f[i][j] = 2;

			if (prv[i] != -1 && prv[i] < j)
				f[i][j] = max(f[i][j], f[j][prv[i]] + 1);
			if (prv[i] != -1 && prv[i] > j)
				f[i][j] = f[prv[i]][j];

			ans = max(ans, f[i][j]);
		}

	cout << ans << endl;


	return 0;
}