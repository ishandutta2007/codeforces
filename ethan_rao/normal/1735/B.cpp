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
		}
		int max = *min_element(all(a)) * 2 - 1;
		for (int &x : a)
		{
			x = (x + max - 1) / max;
		}
		cout << accumulate(all(a), -n) << '\n';
	}
}