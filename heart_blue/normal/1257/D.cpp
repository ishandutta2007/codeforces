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
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, m;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) a[i] = 0;
		cin >> m;
		while (m--)
		{
			int p, s;
			cin >> p >> s;
			a[s] = max(a[s], p);
		}
		for (int i = n - 1; i >= 1; i--) a[i] = max(a[i], a[i + 1]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans++;
			if (b[i] > a[1])
			{
				ans = -1;
				break;
			}
			int j = i;
			int maxv = 0;
			for (j = i; j <= n; j++)
			{
				maxv = max(maxv, b[j]);
				if (a[j - i + 1] < maxv) break;
			}
			i = j - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}