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
#include <bitset>

using namespace std;

int n;

string s;

int main()
{
	cin >> n >> s;
	if (n & 1)
	{
		puts(":(");
		return 0;
	}
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (s[i] == '(')
			cnt++;
	for (int i = 0;i < n;i++)
		if (s[i] == '?')
		{
			if (cnt < n / 2)
				s[i] = '(',cnt++;
			else
				s[i] = ')';
		}
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '(')
			sum++;
		else
			sum--;
		if (sum < 0 || (i < n - 1 && !sum) || (i == n - 1 && sum))
		{
			puts(":(");
			return 0;
		}
	}
	cout << s << endl;
	return 0;
}