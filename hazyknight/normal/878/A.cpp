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

const int MAXN = 500005;

int n;
int v[MAXN];

char tp[MAXN][1];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%s%d",tp[i],&v[i]);
	int AND = 1023,OR = 0,XOR = 0;
	for (int i = 0;i < 10;i++)
	{
		int cur0 = 0,cur1 = 1;
		for (int j = 1;j <= n;j++)
		{
			int V = (v[j] >> i & 1);
			if (tp[j][0] == '&')
			{
				cur0 &= V;
				cur1 &= V;
			}
			if (tp[j][0] == '|')
			{
				cur0 |= V;
				cur1 |= V;
			}
			if (tp[j][0] == '^')
			{
				cur0 ^= V;
				cur1 ^= V;
			}
		}
		if (cur0 == 0 && cur1 == 0)
			AND ^= (1 << i);
		if (cur0 == 1 && cur1 == 0)
			XOR ^= (1 << i);
		if (cur0 == 1 && cur1 == 1)
			OR ^= (1 << i);
	}
	printf("3\n& %d\n| %d\n^ %d\n",AND,OR,XOR);
	return 0;
}