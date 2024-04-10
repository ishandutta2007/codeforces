#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
		{
			cin >> x;
			x &= 1;
		}
		if (n == 1)
		{
			cout << "0\n";
		}
		else
		{
			cout << n - 1 << "\n1 " << n << '\n';
			for (int i = 1; i + 1 < n; i++)
			{
				if (a[i] == a[0])
				{
					cout << i + 1 << ' ' << n << '\n';
				}
				else
				{
					cout << "1 " << i + 1 << '\n';
				}
			}
		}
	}
}