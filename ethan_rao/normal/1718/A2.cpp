#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int N = 100'010;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, ans = 0, cur = 0;
		cin >> n;
		set<int> s = {0};
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			cur ^= x;
			if (s.count(cur))
			{
				s = {0};
				cur = 0;
			}
			else
			{
				s.insert(cur);
				++ans;
			}
		}
		cout << ans << '\n';
	}
}