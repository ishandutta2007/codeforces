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
const int N = 2e5 + 10;
int a[N];
char str[N];
LL p2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	scanf("%s", str + 1);
	p2[0] = 1;
	for (int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % INF;
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + str[i] - '0';
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		int x = a[r] - a[l - 1];
		int y = len - x;
		LL ans = p2[x] - 1;
		LL cur = p2[x] - 1;
		ans += cur * (p2[y] - 1);
		ans %= INF;
		if (ans < 0) ans += INF;
		printf("%lld\n", ans);
	}
	return 0;
}