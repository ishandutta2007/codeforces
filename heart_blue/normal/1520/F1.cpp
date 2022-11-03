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
	int a[N];
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
int sum[N];
int ask(int x)
{
	if (sum[x] != 0x3f3f3f3f)
	{
		return sum[x] + b.sum(x);
	}
	else
	{
		cout << "? 1 " << x << endl;
		int val;
		cin >> val;
		sum[x] = val - b.sum(x);
		return val;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, ncase;
	cin >> n >> ncase;
	MEM(sum, 0x3f);
	while (ncase--)
	{
		int k;
		cin >> k;
		int l = k;
		int r = n;
		int key = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int tot = mid - ask(mid);
			if (tot >= k) key = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << "! " << key << endl;
		b.add(key, 1);
	}
	return 0;
}