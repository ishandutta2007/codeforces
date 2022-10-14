// Codeforces Beta Round #13
// Problem B -- Sequence
#include <cmath>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

#define N 5000

using namespace std;

int n, a[N], b[N];
long long f[2][N];
pair<int, int> t[N];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i != n; ++ i)
	{
		cin >> a[i];
		t[i] = make_pair(a[i], i);
	}
	sort(t, t + n);
	for(int i = 0; i != n; ++ i)
		a[i] = t[i].first,
		b[t[i].second] = i;
	memset(f, 0, sizeof(f));
	for(int i = 0; i != n; ++ i)
	{
		f[i & 1][0] = f[(i + 1) & 1][0] + abs(a[b[i]] - a[0]);
		for(int j = 1; j != n; ++ j)
			f[i & 1][j] = min(f[(i + 1) & 1][j] + abs(a[b[i]] - a[j]), f[i & 1][j - 1]);
	}
	cout << f[(n - 1) & 1][n - 1] << "\n";
	return 0;
}