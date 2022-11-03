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
int ans = INF;
LL a[N];
void solve(LL n, int cur)
{
	if (cur >= ans) return;
	if (n == 0)
	{
		ans = cur;
		return;
	}
	for (int i = 15; i >= 1; i--)
	{
		if (n >= a[i])
		{
			int cnt = n / a[i];
			solve(n % a[i], cur + i * cnt);
			solve(a[i + 1] - n, cur + i + 1);
			break;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	a[1] = 1;
	for (int i = 2; i <= 16; i++)
		a[i] = a[i - 1] * 10 + 1;
	solve(n, 0);
	cout << ans << endl;
	return 0;
}