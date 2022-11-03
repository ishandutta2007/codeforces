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
	ULL a[N];
public:
	void add(int x, ULL val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	ULL sum(int x)
	{
		ULL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b[12];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	k++;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		for (int i = k; i >= 1; i--)
		{
			b[i].add(x, b[i - 1].sum(x - 1));
		}
		b[1].add(x, 1);
	}
	printf("%llu\n", b[k].sum(N - 1));
	return 0;
}