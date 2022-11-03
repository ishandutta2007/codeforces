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
const int N = 1e7 + 10;
LL a[N];
int in[N];
deque<int> l;
inline void add(int x)
{
	if (!in[x])
	{
		in[x] = 1;
		if (!l.empty() && a[l.front()] > a[x]) l.push_front(x);
		else l.push_back(x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0x3f);
	LL n, x, y;
	cin >> n >> x >> y;
	a[0] = 0;
	a[1] = x;
	l.push_back(1);
	MEM(in, 0);
	in[1] = 1;
	while (!l.empty())
	{
		int o = l.front();
		l.pop_front();
		in[o] = 0;
		if (o < n)
		{
			if (a[o + 1] > a[o] + x)
			{
				a[o + 1] = a[o] + x;
				add(o + 1);
			}
		}
		if (a[o - 1] > a[o] + x)
		{
			a[o - 1] = a[o] + x;
			add(o - 1);
		}
		if (2 * o >= n)
		{
			a[n] = min(a[n], a[o] + y + (2 * o - n)*x);
		}
		else
		{
			if (a[2 * o] > a[o] + y)
			{
				a[2 * o] = a[o] + y;
				add(2 * o);
			}
		}
	}
	cout << a[n] << endl;
	return 0;
}