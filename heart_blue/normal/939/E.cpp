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
const int N = 5e5 + 10;
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	double ans = 0;
	int n = 0;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x;
			cin >> x;
			int l = 1, r = n;
			double res = x;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if ((sum[mid] + x) <= (mid + 1) * (sum[mid] - sum[mid - 1])) r = mid - 1;
				else l = mid + 1, res = (sum[mid] + x)*1.0 / (mid + 1);
			}
			ans = max(ans, x - res);
			sum[n + 1] = sum[n] + x;
			n++;
		}
		else printf("%.15f\n", ans);
	}
	return 0;
}