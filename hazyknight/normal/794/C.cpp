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

const int MAXN = 300005;

int ha,ta,hb,tb,n;

char a[MAXN];
char b[MAXN];
char ans[MAXN];

int main()
{
	scanf("%s%s",a + 1,b + 1);
	ha = hb = 1;
	n = ta = tb = strlen(a + 1);
	sort(a + 1,a + ta + 1);
	sort(b + 1,b + tb + 1);
	ta = (n + 1) / 2;
	hb = tb - n / 2 + 1;
	bool cur = 0;
	for (int i = 1;i <= n;i++,cur ^= 1)
	{
		if (a[ha] >= b[tb])
		{
			for (int j = n;j >= i;j--,cur ^= 1)
				ans[j] = cur ? b[hb++] : a[ta--];
			break;
		}
		ans[i] = cur ? b[tb--] : a[ha++];
	}
	for (int i = 1;i <= n;i++)
		putchar(ans[i]);
	putchar('\n');
	return 0;
}