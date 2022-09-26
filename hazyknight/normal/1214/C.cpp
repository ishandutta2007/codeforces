#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

int n;

char s[MAXN];
char t[MAXN];

void check()
{
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		if (t[i] == '(')
			cnt++;
		else
			cnt--;
		if (cnt < 0)
			return;
	}
	if (cnt)
		return;
	puts("Yes");
	exit(0);
}

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 1;i <= n;i++)
		if (s[i] == ')')
		{
			for (int j = 1;j < i;j++)
				t[j] = s[j];
			for (int j = i + 1;j <= n;j++)
				t[j - 1] = s[j];
			t[n] = ')';
			check();
			break;
		}
	for (int i = n;i >= 1;i--)
		if (s[i] == '(')
		{
			t[1] = '(';
			for (int j = 1;j < i;j++)
				t[j + 1] = s[j];
			for (int j = i + 1;j <= n;j++)
				t[j] = s[j];
			check();
			break;
		}
	puts("No");
	return 0;
}