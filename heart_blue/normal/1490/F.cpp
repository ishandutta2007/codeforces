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
int a[N];
LL b[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<int, int> mc1, mc2;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc1[x]++;
		}
		for (auto& p : mc1)
		{
			mc2[p.second]++;
		}
		int ans = INF;
		for (auto& p1 : mc2)
		{
			int sum = 0;
			for (auto& p2 : mc2)
			{
				if (p2.first < p1.first) sum += p2.first * p2.second;
				else sum += (p2.first - p1.first) * p2.second;
			}
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}