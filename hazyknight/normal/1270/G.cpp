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

int T,n;
int to[MAXN];

bool vis[MAXN];

vector<int> ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans.clear();
		for (int i = 0;i < n;i++)
			vis[i] = 0;
		for (int a,i = 1;i <= n;i++)
		{
			scanf("%d",&a);
			to[n - i] = a - i + n;
		}
		int cur = 0;
		while (!vis[cur])
		{
			ans.push_back(cur);
			vis[cur] = 1;
			cur = to[cur];
		}
		reverse(ans.begin(),ans.end());
		while (ans.back() != cur)
			ans.pop_back();
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",n - ans[i]);
		printf("\n");
	}
	return 0;
}