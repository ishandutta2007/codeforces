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

int cnt[2];
int nxt[500005];

string s,t;

void EXIT()
{
	while (cnt[0]--)
		putchar('0');
	while (cnt[1]--)
		putchar('1');
	puts("");
	exit(0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> s >> t;
	for (int i = 0;i < s.size();i++)
		cnt[s[i] - '0']++;
	nxt[0] = nxt[1] = 0;
	for (int i = 1,j = 0;i < t.size();i++)
	{
		while (j && t[i] != t[j])
			j = nxt[j];
		if (t[i] == t[j])
			j++;
		nxt[i + 1] = j;
	}
	for (int i = 0;i < t.size();i++)
	{
		if (!cnt[t[i] - '0'])
			EXIT();
		putchar(t[i]);
		cnt[t[i] - '0']--;
	}
	while (1)
	{
		for (int i = nxt[t.size()];i < t.size();i++)
		{
			if (!cnt[t[i] - '0'])
				EXIT();
			putchar(t[i]);
			cnt[t[i] - '0']--;
		}
	}
	return 0;
}