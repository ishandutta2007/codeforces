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
void change(int l, int r, int k)
{
	for (int i = l; i <= r; i++)
	{
		int x = i + 1;
		if (x > r) x -= k;
		printf("%d ", x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i*a <= n; i++)
	{
		if ((n - i * a) % b) continue;
		for (int j = 1; j <= i*a; j += a)
		{
			change(j, j + a - 1, a);
		}
		for (int j = i * a + 1; j <= n; j += b)
		{
			change(j, j + b - 1, b);
		}
		return 0;
	}
	puts("-1");
	return 0;
}