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
int x[N], y[N], z[N];
double dis(int i, int j)
{
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	int dz = z[i] - z[j];
	return sqrt(dx * dx + dy * dy + dz * dz);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	double ans = INF;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> z[i];
	for (int i = 2; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ans = min(ans, dis(i, j) + dis(1, i) + dis(1, j));
		}
	}
	printf("%.15f\n", ans / 2);
	return 0;
}