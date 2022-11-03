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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, a, b;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		if (a > b) a = n - a + 1, b = n - b + 1;
		vector<int> v(m);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.begin(), v.end());
		while (v.size() > b - a - 1) v.pop_back();
		reverse(v.begin(), v.end());
		int cur = 1;
		int ans = 0;
		for (auto& x : v)
		{
			if (cur + x > b - 1) continue;
			cur++;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}