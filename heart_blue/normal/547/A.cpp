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
const int N = 1e6 + 10;

int flag[N];
LL m;
int moveto(int h, int a, int x, int y)
{
	MEM(flag, 0);
	int cur = 0;
	while (1)
	{
		h = (LL(h)*x + y) % m;
		if (flag[h]) break;
		flag[h] = ++cur;
	}
	return flag[a];
}
int movestep(int h, int tot, int x, int y)
{
	while (tot--)
	{
		h = (LL(h)*x + y) % m;
	}
	return h;
}
void refrain(int &x, int &y, int tot)
{
	LL a = 1, b = 0;
	while (tot--)
	{
		a = a*x % m;
		b = (b*x + y) % m;
	}
	x = a, y = b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h1, a1;
	int x1, y1;
	int h2, a2;
	int x2, y2;
	cin >> m;
	cin >> h1 >> a1;
	cin >> x1 >> y1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
	LL ans = 0;
	LL step = moveto(h1, a1, x1, y1);
	h1 = movestep(h1, step, x1, y1);
	h2 = movestep(h2, step, x2, y2);
	ans += step;
	step = moveto(h1, a1, x1, y1);
	refrain(x2, y2, step);
	for (int i = 0; i <= m; i++)
	{
		if (h2 == a2)
		{
			cout << ans + step*i << endl;
			return 0;
		}
		h2 = (LL(h2)*x2 + y2) % m;
	}
	cout << -1 << endl;
	return 0;
}