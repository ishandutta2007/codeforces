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

int T,n;

char s[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		int tot = 0;
		for (int i = 1;i <= n;i++)
			tot += s[i] - '0';
		if (tot % 3)
		{
			puts("cyan");
			continue;
		}
		bool ok = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j && s[i] == '0' && (s[j] - '0') * 10 % 4 == 0)
					ok = 1;
		puts(ok ? "red" : "cyan");
	}
	return 0;
}