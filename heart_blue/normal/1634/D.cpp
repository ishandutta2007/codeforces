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
const int N = 2e5 + 10;
map<tuple<int, int, int>, int> mc;
int ask(int a, int b, int c)
{
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	if (mc.count({ a,b,c })) return mc[{a, b, c}];
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	int ret;
	cin >> ret;
	mc[{a, b, c}] = ret;
	return ret;
}
void solve4(int a, int b, int c, int d)
{
	int maxv = 0;
	vector<int> v = { a,b,c,d };
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				maxv = max(maxv, ask(v[i], v[j], v[k]));
			}
		}
	}
	int kx = -1, ky = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				if (k == i || k == j) continue;
				if (ask(v[i], v[j], v[k]) == maxv)
					cnt++;
			}
			if (cnt == 2)
				kx = v[i], ky = v[j];
			if (kx != -1) break;
		}
		if (kx != -1) break;
	}
	cout << "! " << kx << ' ' << ky << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		mc.clear();
		int maxv = -1;
		int kx = -1;
		for (int i = 3; i <= n; i++)
		{
			if (ask(1, 2, i) > maxv)
			{
				maxv = ask(1, 2, i);
				kx = i;
			}
		}
		int ky = -1;
		for (int i = 2; i <= n; i++)
		{
			if (kx == i) continue;
			if (ask(1, kx, i) > maxv)
			{
				maxv = ask(1, kx, i);
				ky = i;
			}
		}
		if (ky != -1)
		{
			solve4(1, 2, kx, ky);
			continue;
		}
		int cnt = 0;
		for (int i = 2; i <= n; i++)
		{
			if (kx == i) continue;
			if (ask(1, kx, i) == maxv)
				cnt++;
		}
		if (cnt == n - 2)
			cout << "! " << kx << ' ' << 1 << endl;
		else
		{
			ky = n;
			if (ky == kx) ky--;
			solve4(1, 2, kx, ky);
		}
	}
	return 0;
}