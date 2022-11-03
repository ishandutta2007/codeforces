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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int a[N];
int b[N];
char c[N];
int d[N];
bool solve(int l, int r, int &ptr, int cur)
{
	if (l == r) return true;
	int maxv = 0;
	for (int i = l; i <= r; i++) maxv = max(maxv, a[i]);
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] != maxv) continue;
		if (a[i] > a[i - 1])
		{
			for (int o = i; o > l; o--)
			{
				c[ptr] = 'L';
				d[ptr] = o - l + cur;
				ptr++;
			}
			for (int o = 0; o < r - i; o++)
			{
				c[ptr] = 'R';
				d[ptr] = cur;
				ptr++;
			}
			return true;
		}
	}
	for (int i = l; i < r; i++)
	{
		if (a[i] != maxv) continue;
		if (a[i] > a[i + 1])
		{
			for (int o = 0; o < r - i; o++)
			{
				c[ptr] = 'R';
				d[ptr] = cur + i - l;
				ptr++;
			}
			for (int o = 0; o < i - l; o++)
			{
				c[ptr] = 'L';
				d[ptr] = cur + i - l - o;
				ptr++;
			}
		return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n;
	LL sum1 = 0;
	LL sum2 = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum1 += a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i], sum2 += b[i];
	if (sum1 != sum2)
	{
		cout << "NO" << endl;
		return 0;
	}
	int sum = 0;
	int pre = 1;
	int ptr = 0;
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (sum > b[p])
		{
			cout << "NO" << endl;
			return 0;
		}
		if (sum == b[p])
		{
			if (!solve(pre, i, ptr, p))
			{
				cout << "NO" << endl;
				return 0;
			}
			pre = i + 1;
			sum = 0;
			p++;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n - m; i++)
	{
		cout << d[i] << ' ' << c[i] << '\n';
	}
	return 0;
}