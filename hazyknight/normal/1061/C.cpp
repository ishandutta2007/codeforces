#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n,ans;
int a[MAXN];

vector<int> pos[MAXN];
vector<int> f[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		int cnt = 0;
		for (int j = 1;j * j <= a[i];j++)
			if (a[i] % j == 0)
			{
				if (j <= n)
					pos[j].push_back(i);
				if (a[i] / j <= n && j * j != a[i])
					pos[a[i] / j].push_back(i);
			}
	}
	for (int i = 1;i <= n;i++)
	{
		sort(pos[i].begin(),pos[i].end());
		f[i].resize(pos[i].size());
	}
	for (int i = 0;i < pos[1].size();i++)
	{
		f[1][i] = 1;
		ans++;
	}
	for (int i = 2;i <= n;i++)
	{
		int sum = 0,k = 0;
		for (int j = 0;j < pos[i].size();j++)
		{
			while (k < pos[i - 1].size() && pos[i - 1][k] < pos[i][j])
				(sum += f[i - 1][k++]) %= MOD;
			(ans += (f[i][j] = sum)) %= MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}