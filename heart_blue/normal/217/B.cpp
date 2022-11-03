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
tuple<int, int, int> solve(int n, int a, int b)
{
	int tot = 0;
	int miss = 0;
	int pa = a, pb = b;
	while (a > 0 && b > 0)
	{
		tot += max(a / b, b / a);
		if (a >= b)
		{
			int cost = a / b;
			miss += cost - 1;
			a %= b;
		}
		else
		{
			int cost = b / a;
			miss += cost - 1;
			b %= a;
			if (b == 0) b = a, miss--, tot--;
		}
	}
	if (b != 1 || tot != n) return { int(INF),-1,-1 };
	else return { miss,pa,pb };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r;
	scanf("%d%d", &n, &r);
	tuple<int, int, int> ans = { (int)INF,-1,-1 };
	for (int i = 1; i <= r; i++)
	{
		ans = min(ans, solve(n, i, r));
		ans = min(ans, solve(n, r, i));
	}
	auto [key, a, b] = ans;
	if (key == INF)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	printf("%d\n", key);
	string str;
	str.reserve(n);
	while (a > 0 && b > 0)
	{
		if (a >= b)
		{
			str += 'T';
			a -= b;
		}
		else
		{
			str += 'B';
			b -= a;
		}
	}
	reverse(str.begin(), str.end());
	puts(str.c_str());
	return 0;
}