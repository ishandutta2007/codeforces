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
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	k--;
	LL l = 0, r = INF * INF;
	LL ans = -1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		vector<LL> v;
		for (int i = 1; i <= n; i++)
		{
			LL x = a[i];
			LL d = b[i];
			LL cnt = 0;
			LL cur = 0;
			while (v.size() <= k)
			{
				cnt += x / d;
				cur += x / d;
				if (cnt >= k) break;
				x %= d;
				x += mid;
				v.push_back(cur);
			}
		}
		sort(v.begin(), v.end());
		int flag = 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] < i)
			{
				flag = 0;
				break;
			}
		}
		if (v.size() > k) flag = 0;
		if (flag) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}