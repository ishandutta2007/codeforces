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

int n,cnt[3];

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0;i < n;i++)
		cnt[s[i] - '0']++;
	if (cnt[0] >= n / 3)
	{
		for (int i = n - 1;i >= 0;i--)
		{
			if (cnt[0] == n / 3)
				break;
			if (cnt[2] < n / 3 && s[i] == '0')
			{
				s[i] = '2';
				cnt[0]--;
				cnt[2]++;
			}
			if (cnt[1] < n / 3 && s[i] == '0')
			{
				s[i] = '1';
				cnt[0]--;
				cnt[1]++;
			}
		}
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			if (cnt[0] == n / 3)
				break;
			if (cnt[2] > n / 3 && s[i] == '2')
			{
				s[i] = '0';
				cnt[0]++;
				cnt[2]--;
			}
			if (cnt[1] > n / 3 && s[i] == '1')
			{
				s[i] = '0';
				cnt[0]++;
				cnt[1]--;
			}
		}
	}
	if (cnt[1] >= n / 3)
	{
		for (int i = n - 1;i >= 0;i--)
		{
			if (cnt[1] == n / 3)
				break;
			if (s[i] == '1')
			{
				s[i] = '2';
				cnt[1]--;
				cnt[2]++;
			}
		}
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			if (cnt[1] == n / 3)
				break;
			if (s[i] == '2')
			{
				s[i] = '1';
				cnt[1]++;
				cnt[2]--;
			}
		}
	}
	cout << s << endl;
	return 0;
}