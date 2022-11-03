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
class BIT
{
public:
	int a[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x)
	{
		while (x < N)
		{
			a[x]++;
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	k = min(k, n - k);
	int o = 1;
	LL tot = 1;
	for (int i = 1; i <= n; i++)
	{
		int oo = o + k - 1;
		if (oo > n)
		{
			oo -= n;
			tot += b.sum(oo) + b.sum(n) - b.sum(o);
		}
		else
		{
			tot += b.sum(oo) - b.sum(o);
		}
		tot++;
		b.add(o);
		o += k;
		if (o > n) o -= n;
		b.add(o);
		cout << tot << ' ';
	}
	return 0;
}