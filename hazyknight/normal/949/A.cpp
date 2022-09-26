#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>

using namespace std;

string s;

int tot;

vector<int> zero,one;
vector<int> v[200005];

bool mark[200005];

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '0')
		{
			if (one.empty())
			{
				v[++tot].push_back(i);
				zero.push_back(tot);
			}
			else
			{
				v[one.back()].push_back(i);
				zero.push_back(one.back());
				one.pop_back();
			}
		}
		else
		{
			if (zero.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			v[zero.back()].push_back(i);
			one.push_back(zero.back());
			zero.pop_back();
		}
	}
	if (one.size())
	{
		cout << -1 << endl;
		return 0;
	}
	cout << tot << endl;
	for (int i = 1;i <= tot;i++)
	{
		cout << v[i].size() << ' ';
		for (int j = 0;j < v[i].size();j++)
			cout << v[i][j] + 1 << ' ';
		cout << endl;
	}
	return 0;
}