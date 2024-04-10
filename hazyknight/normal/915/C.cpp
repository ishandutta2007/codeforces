#include <iostream>
#include <cmath>

using namespace std;

string a,b;

int cnt[10];
int ans[20];

void dfs(int depth,bool t)
{
	if (depth >= b.size())
	{
		for (int i = 0;i < depth;i++)
			if (ans[i] != 0)
			{
				for (int j = i;j < depth;j++)
					cout << ans[j];
				cout << endl;
				exit(0);
			}
	}
	if (t)
	{
		for (int i = b[depth] - '0';i >= 0;i--)
			if (cnt[i])
			{
				cnt[i]--;
				ans[depth] = i;
				dfs(depth + 1,(i == b[depth] - '0'));
				cnt[i]++;
			}
	}
	else
	{
		for (int i = 9;i >= 0;i--)
			if (cnt[i])
			{
				cnt[i]--;
				ans[depth] = i;
				dfs(depth + 1,0);
				cnt[i]++;
			}
	}
}

int main()
{
	cin >> a >> b;
	if (a == "0")
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0;i < a.size();i++)
		cnt[a[i] - '0']++;
	if (a.size() < b.size())
	{
		for (int i = 9;i >= 0;i--)
			for (int j = 1;j <= cnt[i];j++)
				cout << i;
		cout << endl;
		return 0;
	}
	if (a.size() > b.size())
		cnt[0] -= a.size() - b.size();
	dfs(0,1);
	return 0;
}