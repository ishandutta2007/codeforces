#pragma comment(linker, "/STACK:102400000,102400000") 
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
const int N = 5e5 + 10;
vector<LL> v;
void dfs(LL x = 0, int tot = 0, int p = 17)
{
	if (tot > 3) return;
	if (p == -1)
	{
		v.push_back(x);
		return;
	}
	x *= 10;
	for (int i = 0; i < 10; i++)
	{
		dfs(x + i, tot + (i > 0), p - 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	dfs();
	v.push_back(LL(1e18));
	sort(v.begin(), v.end());
	while (ncase--)
	{
		LL l, r;
		scanf("%lld%lld", &l, &r);
		auto ans = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
		printf("%d\n", ans);
	}
	return 0;
}