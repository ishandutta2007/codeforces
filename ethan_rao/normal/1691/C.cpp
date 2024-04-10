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
		int r = 0;
		for (i = 0; i < n; i++)
			r += (s[i] - '0') * 11;
		for (i = n - 1; i >= 0; i--)
			if (s[i] == '1')
				break;
		if (i >= 0 && n - 1 - i <= m)
		{
			m -= n - 1 - i;
			swap(s[n - 1], s[i]);
			r -= 10;
		}
		for (i = 0; i < n - 1; i++)
			if (s[i] == '1')
				break;
		if (i < n - 1 && i <= m)
			--r;
		cout << r << '\n';
	}
}