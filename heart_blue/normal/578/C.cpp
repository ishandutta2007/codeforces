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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	double l = -1e4, r = 1e4;
	int cnt = 200;
	auto check1 = [&](double x) -> double
	{
		double maxv = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (sum < 0) sum = a[i] - x;
			else sum += a[i] - x;
			maxv = max(maxv, sum);
		}
		return maxv;
	};
	auto check2 = [&](double x) -> double
	{
		double maxv = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (sum < 0) sum = x - a[i];
			else sum += x - a[i];
			maxv = max(maxv, sum);
		}
		return maxv;
	};
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double midmid = (mid + r) / 2;
		if (max(check1(mid), check2(mid)) > max(check1(midmid), check2(midmid))) l = mid;
		else r = midmid;
	}
	printf("%.15f\n", max(check1(l), check2(l)));
	return 0;
}