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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e6 + 10;
int a[N];
int b[N];
int conn(int x, int y)
{
	while (y)
	{
		x = x * 10 + y % 10;
		y /= 10;
	}
	return x;
}
void init()
{
	MEM(a, 0);
	MEM(b, 0);
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i) a[j] = 1;
	}
	for (int i = 2; i < N; i++)
	{
		a[i] ^= 1;
		a[i] += a[i - 1];
	}
	for (int i = 1; i < N; i++)
	{
		int x = conn(i, i / 10);
		int y = conn(i, i);
		if (x >= N) break;
		b[x] = 1;
		if (y < N) b[y] = 1;
	}
	for (int i = 2; i < N; i++)
	{
		b[i] += b[i - 1];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL p, q;
	cin >> p >> q;
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (a[i] * q <= b[i] * p)
		{
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}