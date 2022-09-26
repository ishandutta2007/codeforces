#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>

using namespace std;

int n;

pair<string,int> s[205];

char ans[205];

bool cmp(const pair<string,int> &a,const pair<string,int> &b)
{
	return a.first.size() < b.first.size();
}

bool ispre(string s,string t)
{
	for (int i = 0;i < t.size();i++)
		if (s[i] != t[i])
			return false;
	return true;
}

bool issuf(string s,string t)
{
	for (int i = t.size() - 1;i >= 0;i--)
		if (s[s.size() - 1 - t.size() + 1 + i] != t[i])
			return false;
	return true;
}

void solve(string S)
{
	for (int i = 1;i <= n;i += 2)
	{
		if (ispre(S,s[i].first) && issuf(S,s[i + 1].first))
		{
			ans[s[i].second] = 'P',ans[s[i + 1].second] = 'S';
			continue;
		}
		if (ispre(S,s[i + 1].first) && issuf(S,s[i].first))
		{
			ans[s[i].second] = 'S',ans[s[i + 1].second] = 'P';
			continue;
		}
		return;
	}
	for (int i = 1;i <= n;i++)
		cout << ans[i];
	cout << endl;
	exit(0);
}

int main()
{
	cin >> n;
	n = n * 2 - 2;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(s + 1,s + n + 1,cmp);
	if (n == 2)
	{
		cout << "PS" << endl;
		return 0;
	}
	solve(s[1].first + s[n - 1].first);
	solve(s[1].first + s[n].first);
	solve(s[2].first + s[n - 1].first);
	solve(s[2].first + s[n].first);
	return 0;
}