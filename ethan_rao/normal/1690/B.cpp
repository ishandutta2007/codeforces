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
		int n, m, i, j, L = 0, R = 1e9;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;
		for (i = 0; i < n; i++)
			if (a[i] < b[i])
				goto no;
		for (i = 0; i < n; i++)
			if (b[i])
			{
				R = min(R, a[i] - b[i]);
				L = max(L, a[i] - b[i]);
			}
			else
			{
				L = max(L, a[i]);
			}
		if (L > R)
			goto no;
		cout << "YES\n";
		continue;
	no:
		cout << "NO\n";
	}
}