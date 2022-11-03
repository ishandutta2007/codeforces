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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	map<int, int> mc;
	for (int i = 1; i < n; i++) mc[abs(a[i] - a[i - 1])] = 1;
	if (mc.count(1)) mc.erase(1);
	if (mc.size() > 1)
	{
		puts("NO");
		return 0;
	}
	if (mc.size() == 0)
	{
		puts("YES");
		puts("1000000000 1");
		return 0;
	}
	int key = mc.begin()->first;
	if (key == 0)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (abs(a[i] - a[i - 1]) != 1) continue;
		int x = a[i], y = a[i - 1];
		if (x > y) swap(x, y);
		if (x%key == 0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("1000000000 %d", key);
	return 0;
}