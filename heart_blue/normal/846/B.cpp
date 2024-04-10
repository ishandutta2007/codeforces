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
int a[N];
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	int sum = 0;
	for (int i = 1; i <= k; i++) cin >> a[i], sum += a[i];
	sort(a + 1, a + k + 1);
	int ans = 0;
	for (int o = 0; o <= n; o++)
	{
		if (o*sum > m) break;
		int res = o * (k + 1);
		int r = m - o * sum;
		for (int i = 1; i <= k; i++)
		{
			int x = min(r / a[i], n - o);
			res += x;
			r -= x * a[i];
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}