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
int flag[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m;
	cin >> m;
	double minv1 = 1e18, maxv1 = 0;
	while (m--)
	{
		int sz = n / k;
		double sum = 0;
		while (sz--)
		{
			int x;
			cin >> x;
			flag[x] = 1;
			sum += a[x];
		}
		minv1 = min(minv1, sum);
		maxv1 = max(maxv1, sum);
	}
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		v1.push_back(a[i]);
		v2.push_back(a[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());
	double minv = 1e18, maxv = 0;
	if (n / k <= v1.size() && v1.size() > n - n / k * k)
	{
		minv = 0;
		maxv = 0;
		for (int i = 0; i < n / k; i++)
		{
			minv += v1[i];
			maxv += v2[i];
		}
	}
	minv = min(minv, minv1);
	maxv = max(maxv, maxv1);
	printf("%.15f %.15f\n", minv / (n / k), maxv / (n / k));
	return 0;
}