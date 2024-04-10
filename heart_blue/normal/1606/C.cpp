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
const int N = 1e3 + 10;
LL p[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1;
	for (int i = 1; i < 10; i++)
		p[i] = p[i - 1] * 10;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		k++;
		LL ans = 0;
		for (int i = 0; i + 1 < v.size(); i++)
		{
			LL o = min(p[v[i + 1]] / p[v[i]] - 1, 1LL * k);
			ans += 1LL * p[v[i]] * o;
			k -= o;
		}
		ans += k * 1LL * p[v.back()];
		printf("%lld\n", ans);
	}
	return 0;
}