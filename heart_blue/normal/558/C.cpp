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
const int N = 1e5 + 10;
int n;
int a[N];
int b[N];
bool ispower2(int x)
{
	return x - (x&-x) == 0;
}
int sum(int x, int y)
{
	int cnt = 0;
	while (x)
	{
		if (y%x == 0)
		{
			if(ispower2(y / x))	return cnt + b[y / x];
		}
		x >>= 1;
		cnt++;
	}
	return INF;
}
int check(int k)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int o = sum(a[i], k);
		if (o == INF) return INF;
		ret += o;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	int minv = INF;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		minv = min(minv, a[i]);
	}
	MEM(b, 0);
	for (int i = 0; (1 << i) < N; i ++)
	{
		b[1 << i] = i;
	}
	int ans = INF;
	while (minv)
	{
		for (int i = minv; i < N; i <<= 1)
		{
			ans = min(ans, check(i));
		}
		minv >>= 1;
	}
	cout << ans << endl;
	return 0;
}