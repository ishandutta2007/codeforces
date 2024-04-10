#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<map>
#include<fstream>
#include<set>
#include <functional>
#include <queue>
using namespace std;
int fun(int n)
{
	return n - n / 4;
}
int main()
{
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++)
	{
		int n;
		cin >> n;
		vector<int>a(n);
		vector<vector<int>>fath(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i]--;
			fath[a[i]].push_back(i);
		}
		int count = 0, pnt = -1;
		vector<int>failers;
		for (int i = 0; i < n; i++)
		{
			if (fath[i].size() == 0)
			{
				failers.push_back(i);
				count++;
				pnt = i;
			}
		}
		if (count == 0)
		{
			cout << n << endl;
			for (int i = 0; i < n; i++)
				cout << a[i] + 1<<' ';
			cout << endl;
		}
		if (count == 1)
		{
			vector<int>usd(n);
			int cur = pnt;
			while (!usd[cur])
			{
				usd[cur] = 1;
				int c = a[cur];
				if (usd[c])
				{
					a[cur] = pnt;
				}
				cur = c;
			}
			cout << n - 1<<endl;
			for (int i = 0; i < n; i++)
				cout << a[i] + 1<<' ';
			cout << endl;
		}
		if (count > 1)
		{
			vector<int>ge(n,-1);
			for (int i = 0; i < n; i++)
			{
				if (fath[i].size() > 0)
				{
					ge[fath[i][0]] = i;
				}
			}
			vector<int>ans(n, -1);
			//cout << failers.size() << endl;
			for (int i = 0; i < failers.size(); i++)
			{
				int cur = failers[i];
				//cout << "FFF " << cur << endl;
				while (ge[cur] != -1)
				{
					ans[cur] = ge[cur];
					cur = ge[cur];
				}
				ans[cur] = failers[(i + 1) % failers.size()];
			//	cout << "sdsd " << cur << ' ' << ans[cur] << endl;
			}
			cout << n - failers.size()<<endl;
			for (int i = 0; i < n; i++)
				if (ans[i] != -1)
					cout << ans[i] + 1 << ' ';
				else
					cout << a[i] + 1 << ' ';
			cout << endl;
		}
	}
}