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
const int N = 2e5 + 20;
LL sum[N];
int nex[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = n;
		int key = l;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (sum[mid] - sum[i - 1] <= k) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		nex[i] = key + 1;
	}
	int res = n;
	for (int i = n; i > 0; i--)
	{
		ans[i] = ans[nex[i]] + 1;
		if (ans[i] <= m)
		{
			res = i;
		}
	}
	cout << n - res + 1 << '\n';
	return 0;
}