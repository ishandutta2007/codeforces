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

const int MAXN = 200005;

int n,q,l,r;
int cnt[MAXN][26];

char s[MAXN];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		memcpy(cnt[i],cnt[i - 1],sizeof(cnt[i]));
		cnt[i][s[i] - 'a']++;
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&l,&r);
		if (l == r || s[l] != s[r])
		{
			puts("Yes");
			continue;
		}
		int tot = 0;
		for (int i = 0;i < 26;i++)
			tot += (cnt[r][i] - cnt[l - 1][i] > 0);
		if (tot > 2)
		{
			puts("Yes");
			continue;
		}
		puts("No");
	}
	return 0;
}