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
const int N = 1e2 + 30;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (n % 2 == 0) puts("0"), exit(0);
	vector<int> v(n);
	for (auto& x : v)
		scanf("%d", &x);
	m = m / (n / 2 + 1) * (n / 2 + 1);
	int l = 0, r = INF;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int flag = 1;
		if (1LL * mid * (n / 2 + 1) > 1LL * m * k)
		{
			r = mid - 1;
			continue;
		}
		int minv = INF;
		for (int i = 0; i < v.size(); i += 2)
		{
			minv = min(minv, v[i]);
		}
		if (minv < mid)
		{
			r = mid - 1;
			continue;
		}
		ans = mid;
		l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}