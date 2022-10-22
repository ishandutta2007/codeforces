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
		ll r = 0;
		cin >> n >> m;
		vector<int> a(n);
		for (int &x : a)
			cin >> x, r += x / m, x %= m;
		sort(all(a));
		reverse(all(a));
		for (i = 0, j = n - 1; i < j; i++)
		{
			while (j > i && a[j] + a[i] < m)
				--j;
			if (j > i)
				++r;
			--j;
		}
		cout << r << '\n';
	}
}