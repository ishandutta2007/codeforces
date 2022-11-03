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
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 41;
int check[M][M][M][M];
int cnt[M][M];
int ans[N];
int k[N];
vector <pair<int,int>> vp[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int chk(int a, int b, int c, int d)
{
	if (a == c)
	{
		if (b == d) return 0;
		else return 1;
	}
	int g = gcd(a, c);
	int x = abs(b - d);
	if (x%g == 0) return 0;
	else return 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int s = 1; s < M; s++)
			{
				for (int t = 0; t < s; t++)
				{
					check[i][j][s][t] = chk(i, j, s, t);
				/*	if (check[i][j][s][t])
					{
						if (i == 2 && j == 0)
						{
							cout << i << ' ' << j << ' ' << s << ' ' << t << endl;
						}
					}*/
				}
			}
		}
	}

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 0; j < k[i]; j++)
		{
			int x;
			scanf("%d", &x);
			vp[x].push_back({ i,j });
		}
	}
	for (int i = 0; i <= m; i++)
	{
		if (vp[i].size() < 2)
		{
			ans[i] = vp[i].size();
			continue;
		}
		int sz = vp[i].size();
		int pre = -INF;
		int l = 0;
		int count = 0;
		int maxv = 0;
		MEM(cnt, 0);
		for (int j = 0; j < vp[i].size(); j++)
		{
			auto p = vp[i][j];
			int cur = p.first;
			int a = k[cur];
			int b = p.second;
			
			if (cur - pre != 1)
			{
				pre = cur;
				auto ptr = check[a][b];
				memcpy(cnt, ptr, sizeof(cnt));
				count = 1;
				maxv = max(maxv, 1);
				l = j;
				continue;
			}
			pre = cur;
			while (cnt[a][b] > 0)
			{
				int x = k[vp[i][l].first];
				int y = vp[i][l].second;
				l++;
				count--;
				auto ptr = check[x][y];
				for (int i = 0; i < M; i++)
				{
					for (int j = 0; j < M; j++)
					{
						cnt[i][j] -= ptr[i][j];
					}
				}
			}
			count++;
			auto ptr = check[a][b];
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cnt[i][j] += ptr[i][j];
				}
			}
			maxv = max(maxv, count);

		}
		ans[i] = maxv;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}