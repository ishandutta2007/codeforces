#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
int n;
int ans = 1e9;
void dfs(ll x, string s, int now)
{
	if (now + n - s.size() >= ans)
		return;
	if (s.size() == n)
	{
		ans = now;
		return;
	}
	int r = -1;
	vector<int> a(10);
	for (auto c : s)
		a[c - '0'] = 1;
	for (int i = 9; i > 1; i--)
		if (a[i])
		{
			dfs(x * i, to_string(x * i), now + 1);
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r = 0;
	ll x;
	cin >> n >> x;
	string s = to_string(x);
	dfs(x, s, 0);
	if (ans == 1'000'000'000)
		ans = -1;
	cout << ans << endl;
	/*if (*max_element(all(s)) == '1')
	{
		cout << "-1\n";
		return 0;
	}
	while (s.size() < n)
	{
		x *= *max_element(all(s)) - '0';
		s = to_string(x);
		++r;
		cout << x << endl;
	}*/
	// cout << r << endl;
}