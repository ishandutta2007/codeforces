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
	scanf("%d", &n);
	map<int, int> mc;
	pair<int, int> maxv = { 0,0 };
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		maxv = max(maxv, { ++mc[a[i]], a[i] });
	}
	printf("%d\n", n - maxv.first);
	int key = maxv.second;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == key && a[i + 1] != key)
		{
			printf("%d %d %d\n", a[i] > a[i + 1] ? 1 : 2, i + 1, i);
			a[i + 1] = key;
		}
	}
	for (int i = n; i > 1; i--)
	{
		if (a[i] == key && a[i - 1] != key)
		{
			printf("%d %d %d\n", a[i] > a[i - 1] ? 1 : 2, i - 1, i);
			a[i - 1] = key;
		}
	}
	return 0;
}