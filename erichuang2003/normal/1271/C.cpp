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

int n,sx,sy;
int ans[4];

int main()
{
	scanf("%d%d%d",&n,&sx,&sy);
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x < sx)
			ans[0]++;
		if (x > sx)
			ans[1]++;
		if (y < sy)
			ans[2]++;
		if (y > sy)
			ans[3]++;
	}
	int MAX = max(max(ans[0],ans[1]),max(ans[2],ans[3]));
	printf("%d\n",MAX);
	if (MAX == ans[0])
		printf("%d %d\n",sx - 1,sy);
	else if (MAX == ans[1])
		printf("%d %d\n",sx + 1,sy);
	else if (MAX == ans[2])
		printf("%d %d\n",sx,sy - 1);
	else
		printf("%d %d\n",sx,sy + 1);
	return 0;
}