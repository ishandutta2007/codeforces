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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e7 + 10;
int a[N];
LL cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	int maxv = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), maxv = max(maxv, a[i]);
	int l = 1, r = maxv;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		fill(cnt + 1, cnt + maxv + 1, 0);
		for (int i = 1; i <= n; i++)
			cnt[a[i]]++;
		LL tot = 0;
		for (int i = maxv; i >= mid; i--)
		{
			if (i / 2 >= mid)
				cnt[i / 2] += cnt[i], cnt[i - i / 2] += cnt[i];
			else
				tot += cnt[i];
		}
		if (tot >= k) 
			ans = mid, l = mid + 1;
		else 
			r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;

}