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

int n,last,ans,a;
int cnt[MAXN];
int val[MAXN];

vector<int> v;

void work(int l,int r)
{
	int tot = 0;
	if (l > r)
		return;
	for (int i = l;i <= r;i++)
		tot += cnt[i];
	if (tot > ans)
	{
		ans = tot;
		int cur = 0;
		for (int i = l;i <= r;i++)
			for (int j = 1;j < cnt[i];j++)
				val[++cur] = i;
		for (int i = r;i >= l;i--)
			val[++cur] = i;
	}
	v.clear();
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
	}
	for (int i = 1;i <= 200000;i++)
	{
		if (!cnt[i])
		{
			work(last,i - 1);
			last = i + 1;
		}
		else if (cnt[i] == 1)
		{
			work(last,i);
			last = i;
		}
	}
	work(last,200000);
	printf("%d\n",ans);
	for (int i = 1;i <= ans;i++)
		printf("%d ",val[i]);
	printf("\n");
	return 0;
}