#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, m, i, j;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> a(n + 1);
		int ans = 1e9;
		for (i = 0; i < n; i++)
			a[i + 1] = a[i] + (s[i] == 'W');
		for (i = m; i <= n; i++)
			ans = min(ans, a[i] - a[i - m]);
		cout << ans << '\n';
	}
}