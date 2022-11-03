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
const int N = 1e6 + 10;
map<int, int> last;
int a[N];
int sum[N];
class BIT
{
public:
	int a[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret ^= a[x];
			x -= lowbit(x);
		}
		return ret;
	}
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] ^= val;
			x += lowbit(x);
		}
	}
} b;
struct Node
{
	int l, r, pos;
	bool operator < (const Node &node)
	{
		if (r != node.r) return r < node.r;
		else return l < node.l;
	}
} qr[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = a[i] ^ sum[i - 1];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &qr[i].l, &qr[i].r);
		qr[i].pos = i;
	}
	sort(qr, qr + m);
	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		if (last[a[i]]) b.add(last[a[i]], a[i]);
		last[a[i]] = i;
		b.add(i, a[i]);
		while (ptr < m && qr[ptr].r < i) ptr++;
		while (ptr < m && qr[ptr].r == i)
		{
			int l = qr[ptr].l, r = qr[ptr].r;
			ans[qr[ptr].pos] = sum[r] ^ sum[l - 1] ^ b.sum(r) ^ b.sum(l - 1);
			ptr++;
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}