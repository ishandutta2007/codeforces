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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int cnt = 0;
		map<int, int> mc;
		int minv = n;
		int o = -1;
		for (int j = i; j <= n * m; j += m)
		{
			o++;
			int x = a[j];
			if (x > n * m) continue;
			if ((x - i) % m)
			{
				cnt++;
			}
			else
			{
				x = (x - i) / m;
				x = (o - x) % n;
				if (x < 0) x += n;
				mc[x]++;
			}
		}
		for (auto& p : mc)
		{
			if (p.first < 0 || p.first >= n) continue;
			minv = min(minv, p.first + n - p.second);
		}
		ans += minv;
	}
	printf("%d\n", ans);
	return 0;
}