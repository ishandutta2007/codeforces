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
const int N = 2e5 + 10;
const LL inf = 4 * INF * INF;
int a[N];
int last[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 1) last[i] = last[i + 1] + 1;
		else last[i] = 0;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		LL tot = 1;
		LL sum = 0;
		while (j <= n)
		{
			if (tot > inf / a[j]) break;
			tot *= a[j];
			sum += a[j];
			if (tot == k * sum)
				ans++;
			if (a[j] == 1)
			{
				if (tot % k == 0)
				{
					LL need = tot / k - sum;
					if (need > 0 && last[j] - 1 >= need)
						ans++;
				}
				sum += last[j] - 1;
				j = j + last[j];
			}
			else
				j++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}