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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e4 + 10;
vector<int> v[N];
int check(int x, int y, int o)
{
	if (x > y) swap(x, y);
	if (x == 0) return y;
	if (abs(x - o) > abs(y - o)) return y;
	else return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tuple<int, int, int, int> ans = { N,1,1,1 };
		for (int i = 1; i < N; i++)
		{
			auto iter = lower_bound(v[i].begin(), v[i].end(), min(a, i));
			int x = *iter;
			if (iter != v[i].begin()) x = check(*iter, *(iter - 1), a);
			int y = i;
			int z = check(c / i * i, (c + i - 1) / i * i, c);
			ans = min(ans, make_tuple(abs(x - a) + abs(y - b) + abs(z - c), x, y, z));
		}
		int res;
		tie(res, a, b, c) = ans;
		printf("%d\n", res);
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}