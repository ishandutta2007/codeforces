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
int sum[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[0][i]);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			sum[i][j] = sum[i - 1][j] ^ sum[i - 1][j + 1];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			sum[i][j] = max(sum[i][j], max(sum[i - 1][j], sum[i - 1][j + 1]));
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r - l][l]);
	}
	return 0;
}