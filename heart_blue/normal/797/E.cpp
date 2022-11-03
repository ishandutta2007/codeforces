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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 320;
int a[N];
vector<pair<int, int>> vp[N];
int ans[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int p, k;
		scanf("%d%d", &p, &k);
		if (k < M) vp[k].push_back({ p,i });
		else
		{
			int res = 0;
			while (p <= n)
			{
				p += a[p] + k;
				res++;
			}
			ans[i] = res;
		}
	}
	for (int i = 1; i < M; i++)
	{
		if (vp[i].empty()) continue;
		for (int j = n; j >= 1; j--)
		{
			sum[j] = 1;
			if (j + a[j] + i <= n) sum[j] += sum[j + a[j] + i];
		}
		for (auto &p : vp[i])
		{
			ans[p.second] = sum[p.first];
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}