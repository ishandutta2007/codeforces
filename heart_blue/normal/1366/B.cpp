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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x, m;
		scanf("%d%d%d", &n, &x, &m);
		int l1 = x, r1 = x;
		while (m--)
		{
			int l2, r2;
			scanf("%d%d", &l2, &r2);
			if (max(l1, l2) <= min(r1, r2))
				l1 = min(l1, l2), r1 = max(r1, r2);
		}
		printf("%d\n", r1 - l1 + 1);
	}
	return 0;
}