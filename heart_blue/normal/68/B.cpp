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
const int N = 3e5 + 10;
double a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	double k;
	cin >> n >> k;
	k = (100 - k) / 100.0;
	double l = 0, r = 1e3;
	for (int i = 0; i < n; i++) cin >> a[i];
	int cnt = 500;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double need = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < mid) need += mid - a[i];
			else need -= (a[i] - mid)* k;
		}
		if (need <= 0) l = mid;
		else r = mid;
	}
	printf("%.15f\n", l);
	return 0;
}