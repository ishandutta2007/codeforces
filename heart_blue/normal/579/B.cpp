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
const int N = 8e2 + 10;
int a[N][N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	n *= 2;
	MEM(ans, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cin >> a[i][j];
		}
	}
	int o = n / 2;
	while (o--)
	{
		int x = 1, y = 1;
		int maxv = -1;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i]) continue;
			for (int j = 1; j < i; j++)
			{
				if (ans[j]) continue;
				if (maxv < a[i][j])
				{
					maxv = a[i][j];
					x = i;
					y = j;
				}
			}
		}
		ans[x] = y;
		ans[y] = x;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}