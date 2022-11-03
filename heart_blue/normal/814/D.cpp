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
const int N = 1e3 + 10;
LL x[N], y[N], r[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld%lld", &x[i], &y[i], &r[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int o = -1;
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (r[i] > r[j]) continue;
			if ((r[i] - r[j])*(r[i] - r[j]) >= (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]))
			{
				o = -o;
				flag = 1;
			}
		}
		if(flag) ans += o * r[i] * r[i];
		else ans += r[i] * r[i];
	}
	printf("%.15f\n", ans*acos(0.0) * 2);
	return 0;
}