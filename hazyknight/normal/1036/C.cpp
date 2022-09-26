#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;

long long pow9[25];

string l,r;

long long C3(long long v)
{
	return v * (v - 1) * (v - 2) / 6;
}

long long C2(long long v)
{
	return v * (v - 1) / 2;
}

long long solve(string p)
{
	if (p == "0")
		return 0;
//	cout << "solve:" << p << endl;
	int cnt = 0;
	long long ret = 0;
	for (int i = 0;i < p.size();i++)
	{
		if (cnt > 3)
			break;
		if (i != 0 && p[i] > '0')
		{
			if (!cnt && p.size() - i - 1 >= 3)
				ret += C3(p.size() - i - 1) * pow9[3];
			if (cnt <= 1 && p.size() - i - 1 >= 2)
				ret += C2(p.size() - i - 1) * pow9[2];
			if (cnt <= 2 && p.size() - i - 1 >= 1)
				ret += (p.size() - i - 1) * pow9[1];
			if (cnt <= 3)
				ret += 1;
		}
		if (p[i] >= '1')
		{
			cnt++;
			if (cnt <= 1 && p.size() - i - 1 >= 2)
				ret += (p[i] - '1') * C2(p.size() - i - 1) * pow9[2];
			if (cnt <= 2 && p.size() - i - 1 >= 1)
				ret += (p[i] - '1') * (p.size() - i - 1) * pow9[1];
			if (cnt <= 3)
				ret += (p[i] - '1');
			cnt--;
		}
		if (p[i] != '0')
			cnt++;
	}
	if (cnt <= 3)
		ret++;
//	cout << "ret:" << ret << endl;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	pow9[0] = 1;
	for (int i = 1;i <= 3;i++)
		pow9[i] = pow9[i - 1] * 9;
	for (int i = 1;i <= n;i++)
	{
		cin >> l >> r;
		l[l.size() - 1]--;
		for (int j = l.size() - 1;j >= 0;j--)
			if (l[j] < '0')
			{
				l[j] = '9';
				l[j - 1]--;
			}
		if (l.size() > 1 && l[0] == '0')
			l.erase(l.begin() + 0);
		long long ans = 0;
		string tmp;
		for (int j = 1;j < l.size();j++)
		{
			tmp += "9";
			ans -= solve(tmp);
		}
		ans -= solve(l);
		tmp = "";
		for (int j = 1;j < r.size();j++)
		{
			tmp += "9";
			ans += solve(tmp);
		}
		ans += solve(r);
		cout << ans << endl;
	}
	return 0;
}