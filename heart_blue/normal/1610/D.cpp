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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL p2[N];
LL cnt[40];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % INF;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		int c = 0;
		while (x % 2 == 0)
		{
			x >>= 1;
			c++;
		}
		cnt[c]++;
	}
	LL ans = 0;
	if (cnt[0] > 0)
		ans = (p2[cnt[0]] - 1) * p2[n - cnt[0]] % INF;
	for (int i = 1; i < 40; i++)
	{
		if (cnt[i] == 0) continue;
		LL key = p2[cnt[i] - 1] - 1;
		for (int j = i + 1; j < 40; j++)
		{
			key = key * p2[cnt[j]] % INF;
		}
		ans += key;
	}
	ans %= INF;
	if (ans < 0) ans += INF;
	printf("%lld\n", ans);
	return 0;
}