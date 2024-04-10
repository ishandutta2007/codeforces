#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e5 + 10;
LL a[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, s;
		cin >> n >> s;
		pair<int, int> ans = { 0,0 };
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + a[i];
			if (sum[i] <= s)
				ans.first = i;
		}
		for (int i = 1; i <= n; i++)
		{
			LL x = s + a[i];
			int pos = upper_bound(sum + 1, sum + n + 1, x) - sum - 1;
			if (pos >= i)
			{
				ans = max(ans, make_pair(pos - 1, -i));
			}
		}
		printf("%d\n", -ans.second);
	}
	return 0;
}