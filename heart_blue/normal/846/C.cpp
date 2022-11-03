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
const int N = 5e3 + 10;
LL sum[N];
pair<LL, int> maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	maxv[n] = make_pair(sum[n], n);
	for (int i = n - 1; i >= 0; i--)
	{
		maxv[i] = max(maxv[i + 1], make_pair(sum[i], i));
	}
	// * sum[a - 1] - 2 * sum[b - 1] + 2 * sum[c - 1] + sum[n];
	tuple<LL, int, int, int> ans = make_tuple(-INF * INF, 0, 0, 0);
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = i; j <= n + 1; j++)
		{
			ans = max(ans,
				make_tuple(sum[n] + 2 * sum[i - 1] - 2 * sum[j - 1] + 2 * maxv[j - 1].first,
					i, j, maxv[j - 1].second + 1));
		}
	}
	int x, y, z;
	tie(ignore, x, y, z) = ans;
	printf("%d %d %d\n", x - 1, y - 1, z - 1);
	return 0;
}