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
int a[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int x)
{
	for (int i = x; i < N; i += lowbit(i)) a[i]++;
}
int sum(int x)
{
	int ret = 0;
	while (x)
	{
		ret += a[x];
		x -= lowbit(x);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	MEM(a, 0);
	int x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		add(x);
		if (sum(x) != x) ans = max(ans, i);
	}
	cout << ans << endl;
	return 0;
}