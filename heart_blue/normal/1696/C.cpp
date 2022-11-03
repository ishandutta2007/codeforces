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
const int N = 1e5 + 10;
vector<pair<int, LL>> check(int n, int m)
{
	vector<pair<int, LL>> vp;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		LL cnt = 1;
		while (x % m == 0)
			x /= m, cnt *= m;
		if (vp.empty() || vp.back().first != x)
			vp.emplace_back(x, cnt);
		else
			vp.back().second += cnt;
	}
	return vp;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		auto vp1 = check(n, m);
		int k;
		scanf("%d", &k);
		auto vp2 = check(k, m);
		if (vp1 == vp2) puts("Yes");
		else puts("No");
	}

	return 0;
}