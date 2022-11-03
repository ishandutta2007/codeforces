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
const int N = 3e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[n + 1] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == -1) continue;
			if (a[i - 1] == -1 || a[i + 1] == -1)
				v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		int k = 0;
		if (!v.empty())
			k = (v.front() + v.back()) / 2;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == -1) a[i] = k;
			if (i > 1) ans = max(ans, abs(a[i] - a[i - 1]));
		}
		printf("%d %d\n", ans, k);
	}
	return 0;
}