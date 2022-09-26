#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,ans;

bool have[1005][26];

string s;

bool cmp(bool *a,bool *b)
{
	for (int i = 0;i < 26;i++)
		if (a[i] ^ b[i])
			return a[i] < b[i];
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 0;j < s.size();j++)
			have[i][s[j] - 'a'] = true;
	}
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (!cmp(have[i],have[j]))
				swap(have[i],have[j]);
	for (int i = 1;i <= n;i++)
		if (cmp(have[i - 1],have[i]))
			ans++;
	cout << ans << endl;
	return 0;
}