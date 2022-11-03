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
const int N = 2e3+ 10;
int deg[N];
int fa[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m[6];
	int w[6];
	int a, b;
	int n = 5;
	for (int i = 1; i <= n; i++) cin >> m[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	cin >> a >> b;
	int ans = 100 * a - 50 * b;
	for (int i = 1; i <= n; i++)
	{
		ans += max(150 * i, (500 - m[i] * 2) * i - 50 * w[i]);
	}
	cout << ans << endl;

	return 0;
}