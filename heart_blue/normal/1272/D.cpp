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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 20;
int pre[N];
int last[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 1;
	pre[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i - 1]) pre[i] = pre[i - 1] + 1;
		else pre[i] = 1;
		ans = max(ans, pre[i]);
	}
	last[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] < a[i + 1]) last[i] = last[i + 1] + 1;
		else last[i] = 1;
		ans = max(ans, last[i]);
	}
	for (int i = 2; i < n; i++)
	{
		if (a[i - 1] < a[i + 1]) ans = max(ans, pre[i - 1] + last[i + 1]);
	}
	cout << ans << endl;
	return 0;
}