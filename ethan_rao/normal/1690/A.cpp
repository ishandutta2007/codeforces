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
		int n, m;
		cin >> n;
		m = n / 3;
		if (n % 3 == 0)
			cout << m << ' ' << m + 1 << ' ' << m - 1 << '\n';
		else if (n % 3 == 1)
			cout << m << ' ' << m + 2 << ' ' << m - 1 << '\n';
		else
			cout << m + 1 << ' ' << m + 2 << ' ' << m - 1 << '\n';
	}
}