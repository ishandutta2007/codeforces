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

typedef long long ll;

int n;

string s;

bool isp(string t)
{
	for (int i = 0,j = t.size() - 1;i < j;i++,j--)
		if (t[i] != t[j])
			return 0;
	return 1;
}

int main()
{
	cin >> s;
	n = s.size();
	char flag = 'a' - 1;
	bool ok = 0;
	for (int i = 0;i < n;i++)
		if (n % 2 == 0 || i != (n - 1) / 2)
		{
			if (flag == 'a' - 1)
				flag = s[i];
			else if (s[i] != flag)
			{
				ok = true;
				break;
			}
		}
	if (!ok)
	{
		puts("Impossible");
		return 0;
	}
	n = s.size();
	for (int i = 0;i < n - 1;i++)
	{
		string t = s.substr(i + 1,n - i - 1) + s.substr(0,i + 1);
		if (isp(t) && s != t)
		{
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}