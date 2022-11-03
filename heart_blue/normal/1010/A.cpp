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
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	double ret = -1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 0; j <= n-1; j++) cin >> b[j];
	b[n] = b[0];
	double l = 0, r = INF;
	int cnt = 400;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double cur = mid;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			cur -= (m + cur) / a[i];
			if (cur < 0) flag = 0;
			cur -= (m + cur) / b[i];
			if (cur < 0) flag = 0;
		}
		if (flag) r = mid;
		else l = mid;
	}
	if (r > 1e9 + 1) puts("-1");
	else printf("%.15f\n", l);
	return 0;
}