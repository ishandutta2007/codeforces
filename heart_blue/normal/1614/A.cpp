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
const int N = 2e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, l, r, k;
		scanf("%d%d%d%d", &n, &l, &r, &k);
		vector<int> v;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (x >= l && x <= r)
				v.push_back(x);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (auto& x : v)
		{
			if (k >= x)
				ans++, k -= x;
		}
		printf("%d\n", ans);
	}
	return 0;
}