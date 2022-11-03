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
int a[N];
double v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double l = 0, r = 1e9;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	int o = 100;
	while (o--)
	{
		double p1, p2;
		double mid = (r + l) / 2;
		p1 = -INF*INF, p2 = INF*INF;
		for (int i = 1; i <= n; i++)
		{
			p1 = max(p1, a[i] - v[i] * mid);
			p2 = min(p2, a[i] + v[i] * mid);
		}
		if (p1 < p2) r = mid;
		else l = mid;
	}
	printf("%.15f\n", l);
	return 0;
}