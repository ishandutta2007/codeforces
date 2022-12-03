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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum ^= x;
	}
	if (n % 2 == 0 && sum > 0) puts("NO"), exit(0);
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i + 2 <= n; i += 2)
	{
		vp.emplace_back(i, i + 1, i + 2);
	}
	for (int i = 1; i + 2 <= n; i += 2)
		vp.emplace_back(i, i + 1, n);
	puts("YES");
	printf("%d\n", vp.size());
	for (auto [x, y, z] : vp)
		printf("%d %d %d\n", x, y, z);
	return 0;
}