#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
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
		vector<pair<int, int> > a(n), b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> ida(n + 1, -1), idb(n + 1, -1);
		for (int i = 0; i < n; i++)
		{
			ida[a[i].second] = i;
			idb[b[i].second] = i;
		}
		queue<int> q;
		q.push(a[n - 1].second);
		string ans(n, '0');
		ans[a[n - 1].second] = '1';
		int wa = n, wb = n;
		while (!q.empty())
		{
			int i = q.front();
			q.pop();
			while (ida[i] < wa)
			{
				wa--;
				if (ans[a[wa].second] == '0')
				{
					ans[a[wa].second] = '1';
					q.push(a[wa].second);
				}
			}
			while (idb[i] < wb)
			{
				wb--;
				if (ans[b[wb].second] == '0')
				{
					ans[b[wb].second] = '1';
					q.push(b[wb].second);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}