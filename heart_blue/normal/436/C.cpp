#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const double eps = 1e-10;
const int N = 1010;
char c[N][11][11];
int flag[N];
int a[N][N];
int dis[N];
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	MEM(c, 0);
	int n, m, k, w;
	scanf("%d%d%d%d", &n, &m, &k, &w);
	getchar();
	vector<int> ans;
	int sum = n*m;
	MEM(flag, 0);
	MEM(dis, 0);
	MEM(a, 0x1f);
	MEM(pre, 0);
	for (int i = 1; i <= k; i++)
	{
		for (int t = 0; t < n; t++)
		{
			gets(c[i][t]);
		}

		
		
		a[0][i] = a[i][0] = n*m;
		for (int j = 1; j < i; j++)
		{
			int cnt = 0;
			int key = 0;
			for (int t = 0; t < n; t++)
			{
				for (int s = 0; s < m; s++)
				{
					if (c[i][t][s] != c[j][t][s])
					{
						cnt++;
						if (cnt *w > n*m) break;
					}
				}
			}
			if(cnt*w < n*m) a[j][i] = a[i][j] = cnt*w;
		}
		
	}
	ans.push_back(1);
	ans.push_back(0);
	flag[1] = 1;
	for (int i = 1; i <= k; i++)
	{
		dis[i] = a[1][i];
		if (dis[i] > n*m) dis[i] = n*m,pre[i] = 0;
		else pre[i] = 1;
	}
	for (int i = 1; i < k; i++)
	{
		int key = 0;
		int minv = n*m + 1;
		for (int j = 1; j <= k; j++)
		{
			if (flag[j]) continue;
			if (dis[j] < minv)
			{
				minv = dis[j];
				key = j;
			}
		}
		flag[key] = 1;
		sum += dis[key];
		ans.push_back(key);
		ans.push_back(pre[key]);
		
		for (int j = 1; j <= k; j++)
		{
			if (dis[j] > a[key][j])
			{
				dis[j] = a[key][j];
				pre[j] = key;
			}
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < ans.size(); i += 2)
	{
		printf("%d %d\n", ans[i], ans[i + 1]);
	}
	

	return 0;
}