#include <bits/stdc++.h>

using namespace std;

int T,n,id;
int a[1005];
int pre[1005];

string ans[1005];

bool vis[1005];

string getstr(int v)
{
	string res;
	while (v > 0)
	{
		res += char('0' + v % 10);
		v /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		id = 0;
		for (int i = 1;i <= n;i++)
			vis[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i] == 1)
			{
				pre[i] = i - 1;
				ans[i] = ans[i - 1] + (i == 1 ? "" : ".") + "1";
			}
			else
			{
				int MN = 1e9;
				for (int j = i - 1;j >= 1;j--)
				{
					if (j <= MN && a[j] == a[i] - 1 && !vis[j])
					{
						pre[i] = j;
						break;
					}
					MN = min(MN,pre[j]);
				}
				vis[pre[i]] = 1;
				ans[i] = ans[pre[i]];
				string num = getstr(a[i]);
				int len = getstr(a[pre[i]]).size();
				if (len < num.size())
					ans[i] += "0";
				for (int j = ans[i].size() - num.size();j < ans[i].size();j++)
					ans[i][j] = num[j - (ans[i].size() - num.size())];
			}
		}
		for (int i = 1;i <= n;i++)
			cout << ans[i] << endl;
	}
	return 0;
}