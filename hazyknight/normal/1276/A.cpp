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

char s[1000005];

bool mark[1000005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		for (int i = 1;i <= n;i++)
			mark[i] = 0;
		for (int i = 1;i + 4 <= n;i++)
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
				mark[i + 2] = 1;
		for (int i = 1;i + 2 <= n;i++)
		{
			if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e' && !mark[i])
				mark[i + 1] = 1;
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && !mark[i + 2])
				mark[i + 1] = 1;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
			ans += mark[i];
		printf("%d\n",ans);
		for (int i = 1;i <= n;i++)
			if (mark[i])
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}