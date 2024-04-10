#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

int n,ans;
int cnt[105];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for (int i = 1;i <= 100;i++)
		if (cnt[i])
		{
			ans++;
			for (int j = i;j <= 100;j += i)
				cnt[j] = 0;
		}
	printf("%d\n",ans);
	return 0;
}