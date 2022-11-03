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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int cnt[N];
int a[100][100];
int getnext(int x, int y)
{
	while (x < N && cnt[x] < y) x++;
	if (x == N) puts("NO"), exit(0);
	return x;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n * n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	int cur = 1;
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 1; j <= n / 2; j++)
		{
			cur = getnext(cur, 4);
			int x[2] = { i,n - i + 1 };
			int y[2] = { j,n - j + 1 };
			cnt[cur] -= 4;
			for (int o1 = 0; o1 < 2; o1++)
			{
				for (int o2 = 0; o2 < 2; o2++)
				{
					a[x[o1]][y[o2]] = cur;
				}
			}
		}
	}
	if (n & 1)
	{
		cur = 1;
		for (int i = 1; i <= n / 2; i++)
		{
			cur = getnext(cur, 2);
			a[n / 2 + 1][i] = a[n / 2 + 1][n - i + 1] = cur;
			cnt[cur] -= 2;
			cur = getnext(cur, 2);
			a[i][n / 2 + 1] = a[n - i + 1][n / 2 + 1] = cur;
			cnt[cur] -= 2;
		}
		cur = 1;
		cur = getnext(cur, 1);
		a[n / 2 + 1][n / 2 + 1] = cur;
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d%c", a[i][j], " \n"[j == n]);
		}
	}
	return 0;
}