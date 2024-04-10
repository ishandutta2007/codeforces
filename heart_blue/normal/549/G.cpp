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
struct Node
{
	int val;
	int pos;
	void init(int i)
	{
		cin >> val;
		pos = i;
	}
	bool operator < (Node &node)
	{
		return val + pos < node.val + node.pos;
	}
} a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i].init(i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		if (a[i].pos + a[i].val < 0)
		{
			puts(":(");
			return 0;
		}
		if (a[i].pos + a[i].val - i > a[i + 1].pos + a[i + 1].val - (i + 1))
		{
			puts(":(");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i].pos + a[i].val - i);
	}
	return 0;
}