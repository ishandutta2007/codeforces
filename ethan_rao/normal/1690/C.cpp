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
		int n, m, i, j, t = 0;
		cin >> n;
		vector<int> a(n), b(n), r(n);
		for (i = 0; i < n; i++)
			cin >> a[i];
		for (i = 0; i < n; i++)
			cin >> b[i];
		for (i = 0; i < n; i++)
		{
			t = max(t, a[i]);
			r[i] = b[i] - t;
			t = b[i];
		}
		for (i = 0; i < n; i++)
			cout << r[i] << " \n"[i + 1 == n];
	}
}