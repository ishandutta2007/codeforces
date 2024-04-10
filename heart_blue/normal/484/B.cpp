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
const int N = 2e6 + 10;
int a[N];
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(a, 0);
	MEM(pre, 0);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x] = 1;
	}
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (a[i]) pre[i + 1] = i;
		if (pre[i]) continue;
		pre[i] = pre[i - 1];
	}
	for (int i = 1; i < N; i++)
	{
		if (a[i] == 0) continue;
		for (int j = 2 * i; j < N; j += i)
		{
			ans = max(ans, pre[j] % i);
		}
	}
	cout << ans << endl;
	return 0;
}