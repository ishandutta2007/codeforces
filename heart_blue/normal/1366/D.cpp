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
const int N = 1e4 + 10;
int a[50 * N];
int b[50 * N];
int p[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		p[k++] = i;
		for (int j = i * i; j < N; j += i)
			a[j] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		int res = 1;
		for (int j = 0; p[j] * p[j] <= x; j++)
		{
			if (x % p[j]) continue;
			while (x % p[j] == 0)
				x /= p[j], res *= p[j];
			break;
		}
		if (res == 1 || x == 1) a[i] = b[i] = -1;
		else a[i] = res, b[i] = x;
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	puts("");
	return 0;
}