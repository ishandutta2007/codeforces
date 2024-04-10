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
	inline int lowbit(int x)
	{
		return x & -x;
	}
	inline int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
	inline void add(int x)
	{
		while (x < N)
		{
			a[x]++;
			x += lowbit(x);
		}
	}
} b;
int readint() 
{
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = readint();
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = readint();
		sum += (i - 1) - b.sum(x);
		b.add(x);
	}
	//cout << sum << endl;
	if (n & 1)
	{
		if (sum & 1) puts("Petr");
		else puts("Um_nik");
	}
	else
	{
		if (sum & 1) puts("Um_nik");
		else puts("Petr");
	}
	return 0;
}