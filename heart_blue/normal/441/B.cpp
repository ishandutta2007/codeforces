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
const int N = 3e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(a, 0);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x] += y;
	}
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		int o = m;
		int t = min(o, a[i - 1]);
		ans += t;
		o -= t;
		t = min(o, a[i]);
		a[i] -= t;
		ans += t;

	}
	cout << ans << endl;
	return 0;
}