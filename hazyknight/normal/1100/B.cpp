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

const int MAXN = 100005;

int n,m,MIN;
int cnt1[MAXN];
int cnt2[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cnt2[MIN = 0] = n;
	for (int a,i = 1;i <= m;i++)
	{
		cin >> a;
		cnt2[cnt1[a]]--;
		cnt2[++cnt1[a]]++;
		if (!cnt2[MIN])
		{
			MIN++;
			putchar('1');
		}
		else
			putchar('0');
	}
	putchar('\n');
	return 0;
}