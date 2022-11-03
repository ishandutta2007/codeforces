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
const int N = 1e2 + 10;
int a[N];
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
		int cnt[3] = { 0,0,0 };
		int avg = n / 3;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			cnt[x % 3]++;
		}
		int ans = 0;
		for (int i = 0; i < 12; i++)
		{
			int o1 = i % 3;
			int o2 = (i + 1) % 3;
			int o = max(0, cnt[o1] - avg);
			ans += o;
			cnt[o1] -= o;
			cnt[o2] += o;
		}
		printf("%d\n", ans);
	}
	return 0;
}