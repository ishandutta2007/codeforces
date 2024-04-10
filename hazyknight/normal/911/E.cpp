#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int n,k,a,MIN = 1;

vector<int> ans;
stack<int> S;

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= k;i++)
	{
		cin >> a;
		while (!S.empty() && a > S.top())
		{
			if (S.top() != MIN)
			{
				cout << -1 << endl;
				return 0;
			}
			MIN++;
			S.pop();
		}
		S.push(a);
		ans.push_back(a);
	}
	while (MIN <= n)
	{
		if (!S.empty() && S.top() == MIN)
			S.pop(),MIN++;
		if (S.empty())
		{
			for (int i = n;i >= MIN;i--)
				ans.push_back(i);
			break;
		}
		while (!S.empty() && S.top() != MIN)
			ans.push_back(S.top() - 1),S.push(S.top() - 1);
	}
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}