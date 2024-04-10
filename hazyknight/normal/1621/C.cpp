#include <bits/stdc++.h>

using namespace std;

int T,n;
int ans[10005];

bool vis[10005];

int query(int x)
{
	cout << "? " << x << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
			vis[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			if (vis[i])
				continue;
			int cur = query(i);
			while (!vis[cur])
			{
				vis[cur] = 1;
				ans[cur] = query(i);
				cur = ans[cur];
			}
		}
		cout << "! ";
		for (int i = 1;i <= n;i++)
			cout << ans[i] << ' ';
		cout << endl;
		cout.flush();
	}
	return 0;
}