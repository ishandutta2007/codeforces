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
		int n, m, i, j, k;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a)
			cin >> x;
		for (i = j = 0; i < n; i = j)
		{
			while (j < n && a[i] == a[j])
				++j;
			if (j == i + 1)
				break;
			for (k = i; k < j; k++)
				b[k] = k - 1;
			b[i] = j - 1;
		}
		if (i < n)
			cout << "-1\n";
		else
			for (i = 0; i < n; i++)
				cout << b[i] + 1 << " \n"[i == n - 1];
	}
}