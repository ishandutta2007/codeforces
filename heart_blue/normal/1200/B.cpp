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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int tot = 0;
		int n, k;
		cin >> n >> tot >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int flag = 1;
		for (int i = 1; i < n; i++)
		{
			int o = max(0, min(a[i], a[i + 1] - k));
			tot += o;
			a[i] -= o;
			if (a[i] + tot + k < a[i + 1])
			{
				flag = 0;
				break;
			}
			int low = max(0, a[i + 1] - k);
			tot -= low - a[i];
			a[i] = low;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}