#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

string s,final_ans;

int sum;

vector<int> v[3];
vector<string> ans;

void judge_ans(string a)
{
	if (a == "")
		return;
	while (a[0] == '0' && a.size() > 1)
		a.erase(a.begin() + 0);
	if (final_ans.size() < a.size())
		final_ans = a;
}

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		sum += s[i] - '0';
		v[(s[i] - '0') % 3].push_back(i);
	}
	if (sum % 3 == 0)
	{
		cout << s << endl;
		return 0;
	}
	else if (sum % 3 == 1)
	{
		if (v[1].size())
		{
			string tmp = s;
			tmp.erase(tmp.begin() + v[1][v[1].size() - 1]);
			judge_ans(tmp);
		}
		if (v[2].size() >= 2)
		{
			string tmp = s;
			tmp.erase(tmp.begin() + v[2][v[2].size() - 1]);
			tmp.erase(tmp.begin() + v[2][v[2].size() - 2]);
			judge_ans(tmp);
		}
	}
	else
	{
		if (v[2].size())
		{
			string tmp = s;
			tmp.erase(tmp.begin() + v[2][v[2].size() - 1]);
			judge_ans(tmp);
		}
		if (v[1].size() >= 2)
		{
			string tmp = s;
			tmp.erase(tmp.begin() + v[1][v[1].size() - 1]);
			tmp.erase(tmp.begin() + v[1][v[1].size() - 2]);
			judge_ans(tmp);
		}
	}
	if (final_ans == "")
		cout << -1 << endl;
	else
		cout << final_ans << endl;
	return 0;
}