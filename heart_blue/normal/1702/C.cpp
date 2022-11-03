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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		map<int, int> mc1, mc2;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (!mc1.count(x))
				mc1[x] = i;
			mc2[x] = i;
		}
		while (q--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (mc1.count(a) && mc2.count(b) && mc1[a] <= mc2[b]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}