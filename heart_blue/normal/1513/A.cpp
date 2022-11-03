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
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		if (k * 2 + 1 > n)
		{
			puts("-1");
			continue;
		}
		MEM(a, 0);
		for (int i = 1; i <= k; i++)
			a[i * 2] = n - i + 1;
		int cur = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0) a[i] = cur++;
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}