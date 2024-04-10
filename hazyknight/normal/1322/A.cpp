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

const int MAXN = 1000005;

int n,top,ans;

pair<int,int> S[MAXN];

char s[MAXN];

int main()
{
	scanf("%d%s",&n,s + 1);
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		bool flag = 0;
		if (cnt < 0)
			flag = 1;
		cnt += (s[i] == '(' ? 1 : -1);
		if (cnt < 0)
			flag = 1;
		ans += flag;
	}
	if (cnt)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}