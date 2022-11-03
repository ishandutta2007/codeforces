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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if (l == r)
		{
			if (l != 1) puts("YES");
			else puts("NO");
		}
		else
		{
			int cnt = (r - l + 1) / 2;
			if ((l & 1) == (r & 1) && r % 2 == 1) cnt++;
			if (cnt <= k) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}