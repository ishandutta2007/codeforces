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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n, m;
		scanf("%d", &n);
		int cnt[2] = { 0,0 };
		while (n--)
		{
			int x;
			scanf("%d", &x);
			cnt[x & 1] ++;
		}
		LL ans = 0;
		scanf("%d", &m);
		while (m--)
		{
			int x;
			scanf("%d", &x);
			ans += cnt[x & 1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}