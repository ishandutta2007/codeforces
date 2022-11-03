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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int v[N];
int t[N];
int u[N];
int n, w, k;
class TreeArray
{
public:
	LL a[N];
	TreeArray()
	{
		MEM(a, 0);
	}
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x, LL y)
	{
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
} ta1,ta2,ta3;
int getT(int w, int tot)
{
	w = min(w, tot);
	int l = 1, r = N - 2;
	int k = 0;
	int ks = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int low = ta1.sum(mid);
		if (low <= tot - w) k = mid, l = mid + 1;
		else r = mid - 1;
	}
	ks = ta1.sum(k);
	int ret = ta2.sum(k) + ta3.sum(N - 2) - ta3.sum(k+1);
	int cnt = ta1.sum(k + 1) - ta1.sum(k);
	int per = cnt == 0 ? 0 : (ta2.sum(k + 1) - ta2.sum(k)) / cnt;
	if (ks <= tot - w)
	{
		int o = tot - w - ks;
		ret += o*per + (cnt - o)*((per + 1) / 2);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &w, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		u[i] = t[i];
	}
	sort(u, u + n);
	int p = 0;
	LL ans = 0;
	LL res = 0;
	for (int i = 0; i < n; i++)
	{
		while (p < n)
		{
			int o = lower_bound(u, u + n, t[p]) - u + 1;
			ta1.add(o, 1);
			ta2.add(o, t[p]);
			ta3.add(o, (t[p] + 1) / 2);
			if (getT(w, p - i + 1) <= k) ans += v[p++];
			else
			{
				ta1.add(o, -1);
				ta2.add(o, -t[p]);
				ta3.add(o, -(t[p] + 1) / 2);
				break;
			}
		}
		res = max(res, ans);
		ans -= v[i];
		int o = lower_bound(u, u + n, t[i]) - u + 1;
		ta1.add(o, -1);
		ta2.add(o, -t[i]);
		ta3.add(o, -(t[i] + 1) / 2);
	}
	cout << res << endl;

	return 0;
}