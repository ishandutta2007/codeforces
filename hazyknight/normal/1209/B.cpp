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

int n,a,b,ans;
int cnt[10005];

char s[105];

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&a,&b);
		int cur = s[i] - '0';
		for (int j = 0;j <= 10000;j++)
		{
			if (j >= b && (j - b) % a == 0)
				cur ^= 1;
			cnt[j] += cur;
		}
	}
	for (int i = 0;i <= 10000;i++)
		ans = max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}