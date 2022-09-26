#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

bool check(string x,string y)
{
	if (x.size() > y.size())
		return false;
	for (int i = x.size() - 1,j = y.size() - 1;i >= 0;i--,j--)
		if (x[i] != y[j])
			return false;
	return true;
}

map<string,int> match;

vector<string> arr[25];

int n,id,cnt,now,len;

string s;
string name[125];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		if (!match[s])
		{
			match[s] = ++cnt;
			name[cnt] = s;
		}
		now = match[s];
		cin >> len;
		for (int j = 1;j <= len;j++)
		{
			cin >> s;
			arr[now].push_back(s);
		}
	}
	for (int i = 1;i <= cnt;i++)
	{
		for (int j = 0;j < arr[i].size();j++)
		{
			bool flag = 0;
			for (int k = 0;k < arr[i].size();k++)
				if (j != k && check(arr[i][j],arr[i][k]))
				{
					flag = true;
					break;
				}
			if (flag)
			{
				arr[i].erase(arr[i].begin() + j);
				j--;
			}
		}
	}
	cout << cnt << endl;
	for (int i = 1;i <= cnt;i++)
	{
		cout << name[i] << ' ' << arr[i].size() << ' ';
		for (int j = 0;j < arr[i].size();j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	return 0;
}