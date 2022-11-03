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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int flag = 1;
	int w, m;
	cin >> w >> m;
	int n = 0;
	MEM(a, 0);
	while (m)
	{
		a[n++] = m%w;
		m /= w;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == w) a[i] = 0, a[i + 1]++;
		if (a[i] == w - 1 || a[i] == 1)
		{
			if (a[i] != 1)
			{
				a[i] = 0;
				a[i + 1]++;
			}
		}
		if (a[i] > 1)
		{
			flag = 0;
			break;
		}
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}