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
const int N = 5e3 + 10;
int a[N];
int b[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 1; j < i; j++)
		{
			if (a[i] < a[j])
				ans++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = i; j >= 0; j--)
		{
			b[i][j] = cnt;
			if (a[i] > a[j]) cnt++;
			else cnt--;
		}
		cnt = 0;
		for (int j = i; j <= n; j++)
		{
			if (a[i] > a[j]) cnt--;
			else cnt++;
			b[i][j] = cnt;
		}
	}
	int minv = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (minv > b[i][j] + b[j][i])
			{
				minv = b[i][j] + b[j][i];
				cnt = 0;
			}
			if (minv == b[i][j] + b[j][i])
				cnt++;
		}
	}

	printf("%d %d\n", ans + minv, cnt);
	return 0;
}