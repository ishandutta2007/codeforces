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
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 40;
int nex[M][N];
int minv[M][N];
LL sum[M][N];
LL ans1[N];
int ans2[N];
int cur[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &nex[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &minv[0][i]), sum[0][i] = minv[0][i];
	MEM(ans2, 0x3f);
	for (int o = 0; o + 1 < M; o++)
	{
		for (int i = 0; i < n; i++)
		{
			int fa = nex[o][i];
			sum[o + 1][i] = sum[o][i] + sum[o][fa];
			minv[o + 1][i] = min(minv[o][i], minv[o][fa]);
			nex[o + 1][i] = nex[o][fa];
		}
	}
	for (int i = 0; i < n; i++)
		cur[i] = i;
	for (int o = 0; k >> o; o++)
	{
		if (k >> o & 1)
		{
			for (int i = 0; i < n; i++)
			{
				ans1[i] += sum[o][cur[i]];
				ans2[i] = min(ans2[i], minv[o][cur[i]]);
				cur[i] = nex[o][cur[i]];
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld %d\n", ans1[i], ans2[i]);
	return 0;
}