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
		vector<int> a(2);
		while (n--)
		{
			cin >> m;
			++a[m & 1];
		}
		cout << *min_element(all(a)) << '\n';
	}
}