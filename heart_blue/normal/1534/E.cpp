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
const int N = 4e5 + 10;
int a[N];
void output(int l1, int r1)
{
	for (int i = l1; i <= r1; i++)
		cout << ' ' << i;
}
void solve0(int n, int k)
{
	if (n == k)
	{
		cout << "?";
		output(1, n);
		cout << endl;
		int x;
		cin >> x;
		cout << "! " << x << endl;
		exit(0);
	}
}
int refrain(int n, int k, int l, int r)
{
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		if (i < l || i > r)
			v.push_back(i);
	}
	int x;
	int ret = 0;
	int len = (r - l + 1) / 2;
	int rest = k - len;
	while (v.size() > rest) v.pop_back();
	cout << "?";
	for (int i = 0; i < len; i++)
		cout << ' ' << l + i;
	for (auto& x : v)
		cout << ' ' << x;
	cout << endl;
	cin >> x;
	ret ^= x;
	cout << "?";
	for (int i = 0; i < len; i++)
		cout << ' ' << r - i;
	for (auto& x : v)
		cout << ' ' << x;
	cout << endl;
	cin >> x;
	ret ^= x;
	return ret;
}
void solve3(int n, int k)
{
	if (n > k && n < 2 * k)
	{
		int o = 0;
		for (int i = 2; i <= k; i += 2)
		{
			if (n - i >= k - i / 2)
			{
				o = i;
			}
		}
		int cur = 0;
		int ret = 0;
		while (cur < n)
		{
			ret ^= refrain(n, k, cur + 1, min(cur + o, n));
			cur += o;
		}
		cout << "! " << ret << endl;
		exit(0);
	}
}
void solve2(int n, int k)
{
	int o = n % k;
	if (o % 2 == 1)
	{
		if (o + k == n) return;
		o += k;
	}
	else if ((k + o) % 2 == 0)
	{
		if (o + k != n && o != 0)
			o += k;
	}
	int ans = 0;
	if (o <= k)
	{
		if (o > 0)
			ans ^= refrain(n, k, 1, o);
	}
	else
	{
		ans ^= refrain(n, k, 1, o);
	}
	while (o < n)
	{
		int x;
		cout << "?"; output(o + 1, o + k); cout << endl;
		cin >> x;
		ans ^= x;
		o += k;
	}
	cout << "! " << ans << endl;
	exit(0);
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n % 2 == 1 && k % 2 == 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	solve0(n, k);
	solve2(n, k);
	solve3(n, k);
	return 0;
}