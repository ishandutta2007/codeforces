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
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		int cnt = 0;
		for (int i = 1; i < n; i++)
		{
			mc[a[i]]++;
			mc[b[i]]--;
			if (mc[a[i]] == 0) mc.erase(a[i]);
			if (mc[b[i]] == 0) mc.erase(b[i]);
			if (mc.empty())
			{
				cnt++;
			}
		}
		if (cnt != n - 1) puts("YES");
		else puts("NO");

	}
	return 0;
}