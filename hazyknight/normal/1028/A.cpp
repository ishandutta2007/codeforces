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

int n,m;
int X,Y,cnt;

char s[150];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s + 1);
		for (int j = 1;j <= m;j++)
			if (s[j] == 'B')
			{
				X += i;
				Y += j;
				cnt++;
			}
	}
	printf("%d %d\n",X / cnt,Y / cnt);
	return 0;
}