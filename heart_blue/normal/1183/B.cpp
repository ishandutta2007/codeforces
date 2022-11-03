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
const int N = 5e3 + 10;
void combine(int& l1, int& r1, int l2, int r2)
{
	l1 = max(l1, l2);
	r1 = min(r1, r2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int l = 1, r = INF;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			combine(l, r, x - k, x + k);
		}
		l = max(1, l);
		if (r < l) puts("-1");
		else printf("%d\n", r);
	}
	return 0;
}