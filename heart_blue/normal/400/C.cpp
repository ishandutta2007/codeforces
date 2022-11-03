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
class Solver
{
public:
	int n, m;
	Solver(int n, int m)
	{
		this->n = n;
		this->m = m;
	}
	void rot90(int &x, int &y)
	{
		tie(x, y) = make_pair(y, n - x + 1);
		swap(n, m);
	}
	void mir(int &x, int &y)
	{
		y = m - y + 1;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int x, y, z;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &x, &y, &z);
	x %= 4;
	y %= 2;
	z %= 4;
	z = (4 - z) % 4;
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Solver s(n, m);
		int xx = x, yy = y, zz = z;
		while (xx--) s.rot90(a, b);
		while (yy--) s.mir(a, b);
		while (zz--) s.rot90(a, b);
		printf("%d %d\n", a, b);
	}

	return 0;
}