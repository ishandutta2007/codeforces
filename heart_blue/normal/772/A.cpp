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
const int N = 1e5 + 10;
LL a[N];
LL b[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	cin >> n >> p;
	LL tot = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], tot += a[i];
	if (tot <= p)
	{
		cout << -1 << endl;
		return 0;
	}
	double l = 0, r = 1e18;
	while (r - l > 1e-6)
	{
		double mid = (l + r) / 2;
		double cost = 0;
		for (int i = 1; i <= n; i++)
		{
			cost += max(0.0, a[i] * mid - b[i]);
		}
		if (cost > p * mid) r = mid;
		else l = mid;
	}
	printf("%.15f\n", l);
	return 0;
}