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
const int N = 1e6 + 10;
const int mod = 998244353;
LL ans[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			ans[j]++;
		}
	}
	int pre = 0;
	for (int i = 1; i < N; i++)
	{
		ans[i] += pre;
		pre += ans[i];
		pre %= mod;
		ans[i] %= mod;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	printf("%lld\n", ans[n]);
	return 0;
}