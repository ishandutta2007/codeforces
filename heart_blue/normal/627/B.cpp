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
class BIT
{
public:
	LL a[N];
	inline int lowbit(int x)
	{
		return x&-x;
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
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
} b1, b2;
int cur[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int d, x;
			cin >> d >> x;
			b1.add(d, -min(b, cur[d]));
			b2.add(d, -min(a, cur[d]));
			cur[d] += x;
			b1.add(d, min(b, cur[d]));
			b2.add(d, min(a, cur[d]));
		}
		else
		{
			int l;
			cin >> l;
			int r = l + k - 1;
			printf("%lld\n", b1.sum(l - 1) + b2.sum(n) - b2.sum(r));
		}
	}
	return 0;
}