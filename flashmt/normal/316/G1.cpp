#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

string s, t[11];
int n, l[11], r[11], pre[222];
set <string> has[222];

void preKMP(int pre[], string t)
{
	int i = 0, j = -1, n = t.size();
	pre[0] = -1;
	while (i < n)
	{
		while (j >= 0 && t[i] != t[j]) j = pre[j];
		i++; j++;
		pre[i] = (j >= n || t[i] != t[j] ? j : pre[j]);
	}
}

int match(string s, string t, int pre[], int low, int high)
{
	int i = 0, j = 0, m = s.size(), n = t.size(), cnt = 0;
	while (i < m)
	{
		while (j >= 0 && s[i] != t[j]) j = pre[j];
		i++; j++;
		if (j == n) cnt++, j = pre[j];
	}
	return low <= cnt && cnt <= high;
}

int ok(string s)
{
	preKMP(pre, s);
	for (int i = 0; i < n; i++)
		if (!match(t[i], s, pre, l[i], r[i]))
			return 0;
	return 1;
}

int main()
{
	cin >> s >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> l[i] >> r[i];
	
	int L = s.size(), ans = 0;
	for (int i = 0; i < L; i++)
		for (int j = i; j < L; j++)
		{
			string ss = s.substr(i, j - i + 1);
			if (has[j - i].count(ss)) continue; 
			has[j - i].insert(ss);
			if (ok(ss)) ans++;
		}
			
	cout << ans << endl;
}