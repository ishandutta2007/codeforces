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
const int N = 3e5 + 10;
LL b[N];
LL sumd[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	LL ans = 0;
	LL cur = 0;
	LL d = 0;
	for (int i = n; i >= 1; i--)
	{
		k = min(k, i);
		cur -= d;
		d += sumd[i];
		if (cur < b[i])
		{
			LL o = (b[i] - cur + k - 1) / k;
			cur += o * k;
			d += o;
			sumd[i - k] -= o;
			ans += o;
		}
	}
	printf("%lld\n", ans);
	return 0;
}