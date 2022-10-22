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
		int n, m, i, j, x = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;
		cin >> m;
		while (m--)
		{
			int y;
			cin >> y;
			x = (x + y) % n;
		}
		cout << a[x] << '\n';
	}
}