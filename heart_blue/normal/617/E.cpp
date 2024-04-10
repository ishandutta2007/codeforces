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
const int N = 2e6 + 10;
const int M = 355;
int cnt[N];
int sum[N];
LL res[N];
LL ans = 0;
int n, m, k;
struct Node
{
	int l, r;
	int pos;
	bool operator < (Node &node)
	{
		if (l / M != node.l / M) return l / M < node.l / M;
		else return r < node.r;
	}
} qr[N];
inline void modify(int x, int o)
{
	if (k != 0) ans += cnt[x^k] * o;
	else
	{
		if (o > 0) ans += cnt[x];
		else ans -= cnt[x] - 1;
	}
	cnt[x] += o;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	sum[1] = 0;
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> sum[i];
		sum[i] ^= sum[i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> qr[i].l >> qr[i].r;
		qr[i].r++;
		qr[i].pos = i;
	}
	sort(qr + 1, qr + m + 1);
	int L = 1, R = 0;
	for (int i = 1; i <= m; i++)
	{
		int l = qr[i].l, r = qr[i].r;
		while (L > l) modify(sum[--L], 1);
		while (R < r) modify(sum[++R], 1);
		while (L < l) modify(sum[L++], -1);
		while (R > r) modify(sum[R--], -1);
		res[qr[i].pos] = ans;
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%lld\n", res[i]);
	}
	return 0;
}