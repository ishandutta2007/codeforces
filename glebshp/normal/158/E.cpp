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

const int size = 4 * 1000 + 10;
const int tmsize = 86400;

int ans[size][size];
int t[size], d[size];

int main() {
	int n, ans_val = 0, k;

	//freopen("problemE.in", "r", stdin);
	//freopen("problemE.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> d[i];
	ans[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i][0] = max(ans[i - 1][0] + 1, t[i - 1]) + d[i - 1] - 1;
		for (int j = 1; j <= i; j++)
			ans[i][j] = min(max(ans[i - 1][j] + 1, t[i - 1]) + d[i - 1] - 1, ans[i - 1][j - 1]);
	}
	for (int i = 0; i < n; i++)
		ans_val = max(ans_val, t[i] - ans[i][k] - 1);
	ans_val = max(ans_val, tmsize - ans[n][k]);
	cout << ans_val << endl;

	return 0;
}