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

const int MAXN = 400005;

int n,m,A,B,ANS;

pair<int,int> cnt[MAXN];
vector<int> ans[MAXN];
map<int,int> match;

int main()
{
	scanf("%d",&n);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		if (!match[a])
		{
			match[a] = ++m;
			cnt[match[a]].second = a;
		}
		a = match[a];
		cnt[a].first++;
	}
	sort(cnt + 1,cnt + m + 1);
	for (int i = 1,j = 1,tot = 0;;i++)
	{
		while (j <= m && cnt[j].first < i)
			j++;
		tot += m - j + 1;
		if (tot / i < i)
			break;
		if (tot / i * i > ANS)
		{
			ANS = tot / i * i;
			A = i;
			B = tot / i;
		}
	}
	for (int i = 1;i <= A;i++)
		ans[i].resize(B + 1);
	for (int i = 1;i <= m;i++)
		cnt[i].first = min(cnt[i].first,A);
	int cur = m;
	for (int d = 0;d < B;d++)
		for (int i = 1;i <= A;i++)
		{
			if (!cnt[cur].first)
				cur--;
			ans[i][(i + d - 1) % B + 1] = cnt[cur].second;
			cnt[cur].first--;
		}
	printf("%d\n",ANS);
	printf("%d %d\n",A,B);
	for (int i = 1;i <= A;i++,printf("\n"))
		for (int j = 1;j <= B;j++)
			printf("%d ",ans[i][j]);
	return 0;
}