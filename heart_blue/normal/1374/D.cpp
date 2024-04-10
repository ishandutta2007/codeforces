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
int solve(string& str)
{
	for (auto& c : str)
		c ^= '(' ^ ')';
	reverse(str.begin(), str.end());
	int cur = 0;
	int minv = 0;
	for (auto& c : str)
	{
		if (c == '(')
			cur++;
		else
			cur--;
		minv = min(minv, cur);
	}
	return -minv;
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		map<int, int> mc;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[(k - x % k) % k]++;
		}
		int maxv = 0;
		LL ans = 0;
		for (auto& p : mc)
		{
			if (p.first == 0) continue;
			if (p.second >= maxv)
			{
				maxv = p.second;
				ans = (p.second - 1LL) * k + p.first + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}