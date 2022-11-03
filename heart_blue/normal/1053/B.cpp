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
const int N = 3e5 + 10;
int a[N];
int next1[N];
int sum[N];
int sum1[N];
int sum0[N];
int pos[N];
vector<int> v;
int getcnt(LL x)
{
	int ret = 0;
	while (x)
	{
		x -= x & -x;
		ret++;
	}
	return ret;
}
void combine(int &l, int &r, int x)
{
	if (r >= x)
	{
		l = l - x;
		r = r + x;
	}
	else
	{
		l = x - r;
		r = x + r;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		LL x;
		scanf("%lld", &x);
		a[i] = getcnt(x);
	}
	//LL res = 0;
	//int res2 = 0;
	//for (int i = 1; i <= n; i++)
	//{
	//	int l = a[i];
	//	int r = a[i];
	//	int tot = a[i] & 1;
	//	int c = 0;
	//	for (int j = i + 1; j <= n; j++)
	//	{
	//		tot ^= a[j] & 1;
	//		l = max(tot, l - a[j]);
	//		r = r + a[j];
	//		if (l == 0) res++, c++;
	//	}
	//	cout << i << ' ' << c << endl;
	//}
	//cout << res2 << endl;
	//cout << res << endl;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1];
		sum[i] ^= a[i] & 1;
	}
	for (int i = n; i > 0; i--)
	{
		sum1[i] = sum1[i + 1];
		sum0[i] = sum0[i + 1];
		if (sum[i] & 1) sum1[i]++;
		else sum0[i]++;
	}
	next1[n + 1] = n + 1;
	next1[n + 2] = n + 2;
	next1[n + 3] = n + 3;
	int cnt = 0;
	for (int i = n; i >= 1; i--)
	{
		next1[i] = next1[i + 1];
		if (a[i] & 1)
		{
			next1[i] = i;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int o = min(n, i + 64);
		int l = a[i];
		int r = a[i];
		int tot = a[i] & 1;
		int c = 0;
		for (int j = i + 1; j <= o; j++)
		{
			tot ^= a[j] & 1;
			combine(l, r, a[j]);
			l = max(tot, l);
			if (l == 0) ans++, c++;
		}
		if (tot & 1)
		{
			if (sum[o] & 1) ans += sum0[o + 1], c += sum0[o + 1];
			else ans += sum1[o + 1], c += sum1[o + 1];
		}
		else
		{
			if (sum[o] & 1) ans += sum1[o + 1], c += sum1[o + 1];
			else ans += sum0[o + 1], c += sum0[o + 1];
		}
		//cout << i << ' ' << c << endl;
	}
	printf("%lld\n", ans);
	return 0;
}