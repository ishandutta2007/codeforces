#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 2005;

int T,n,k;

char s[MAXN];

vector<pair<int,int> > ans;

void work(char c,int p)
{
	if (s[p] == c)
		return;
	for (int i = p + 1;i <= n;i++)
		if (s[i] == c)
		{
			ans.push_back(make_pair(p,i));
			reverse(s + p,s + i + 1);
			return;
		}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%s",&n,&k,s + 1);
		ans.clear();
		for (int i = 1;i <= n;i++)
		{
			if ((i - 1) / 2 < k - 1)
			{
				if (i & 1)
					work('(',i);
				else
					work(')',i);
			}
			else
			{
				if (i <= n - (n - 2 * (k - 1)) / 2)
					work('(',i);
				else
					work(')',i);
			}
		}
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}