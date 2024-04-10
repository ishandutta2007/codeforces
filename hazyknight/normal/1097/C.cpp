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
#include <fstream>

using namespace std;

int n,ans;

pair<int,int> cnt[500005];

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		bool okf = true,okb = true;
		int c = 0;
		for (int j = 0;j < s.size();j++)
		{
			if (s[j] == '(')
				c++;
			else
				c--;
			if (c < 0)
				okf = false;
		}
		int t = c;
		c = 0;
		for (int j = s.size() - 1;j >= 0;j--)
		{
			if (s[j] == ')')
				c++;
			else
				c--;
			if (c < 0)
				okb = false;
		}
		if (okf && okb)
			ans++;
		else if (okf)
			cnt[t].first++;
		else if (okb)
			cnt[c].second++;
	}
	ans >>= 1;
	for (int i = 1;i <= 500000;i++)
		ans += min(cnt[i].first,cnt[i].second);
	cout << ans << endl;
	return 0;
}