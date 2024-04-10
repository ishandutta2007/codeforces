#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int b = sqrt(n);
		vector<vector<ll> > v(n);
		vector<int> u(n), s(n);
		for (int i = 0; i < n; i++) cin >> u[i], u[i]--;
		for (int i = 0; i < n; i++) cin >> s[i], v[u[i]].push_back(s[i]);
		vector<int> big;
		for (int it = 0; it < n; it++)
		{
			vector<ll>& i = v[it];
			sort(i.begin(), i.end(), greater<ll>());
			i.insert(i.begin(), 0);
			for (int j = 1; j < i.size(); j++)
				i[j] += i[j - 1];
			if (i.size() >= b) big.push_back(it);
		}
		vector<ll> ans(n + 1, 0);
		for (int i = 1; i < b; i++)
		{
			for (int j = 0; j < n; j++)
				ans[i] += v[j][((v[j].size() - 1) / i) * i];
		}
		for (int i = b; i <= n; i++)
		{
			for (int j : big)
				ans[i] += v[j][((v[j].size() - 1) / i) * i];
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
	}
	return 0;
}