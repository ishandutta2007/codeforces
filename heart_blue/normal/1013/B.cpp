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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
		if (cnt[x] > 1)
		{
			puts("0");
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i != (i & k))
		{
			if (cnt[i] == 1 && cnt[i&k] == 1)
			{
				puts("1");
				return 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i == (i&k)) continue;
		if (cnt[i] == 0) continue;
		cnt[i&k]++;
		cnt[i]--;
	}
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] > 1)
		{
			puts("2");
			return 0;
		}
	}
	puts("-1");
	return 0;
}