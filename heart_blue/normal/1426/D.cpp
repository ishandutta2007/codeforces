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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	map<LL, int> mc;
	mc[0] = 1;
	LL sum = 0;
	int ans = 0;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		sum += x;
		if (mc.count(sum))
		{
			ans++;
			mc.clear();
			mc[0] = 1;
			mc[x] = 1;
			sum = x;
		}
		else
			mc[sum] = 1;
	}
	printf("%d\n", ans);
	return 0;
}