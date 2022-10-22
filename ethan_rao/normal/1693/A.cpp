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
		cin >> n;
		vector<ll> a(n);
		for (ll &x : a)
			cin >> x;
		for (i = 1; i < n; i++)
			a[i] += a[i - 1];
		for (i = 0; i < n; i++)
			if (a[i] == 0)
				break;
		for (; i < n; i++)
			if (a[i])
				break;
		if (!a[n - 1] && *min_element(all(a)) >= 0 && i == n)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}