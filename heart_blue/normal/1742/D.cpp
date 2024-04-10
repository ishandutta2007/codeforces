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
const int N = 3e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x] = max(mc[x], i);
		}
		int ans = -1;
		for (auto& [a1, b1] : mc)
		{
			for (auto& [a2, b2] : mc)
			{
				if (gcd(a1, a2) == 1)
				{
					ans = max(ans, b1 + b2);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}