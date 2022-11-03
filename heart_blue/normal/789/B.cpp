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
const int N = 2e5 + 10;
map<LL, int> mc;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL b, q, l, m;
	cin >> b >> q >> l >> m;
	while (m--)
	{
		LL x;
		cin >> x;
		mc[x] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		if (abs(b) > l) break;
		if (!mc.count(b)) cnt++;
		b *= q;
	}
	if (cnt >= N) puts("inf");
	else printf("%d\n", cnt);

	return 0;
}