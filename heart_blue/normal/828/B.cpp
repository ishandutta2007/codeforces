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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int l, r, u, d;
	l = m, r = 0, u = n, d = 0;
	int minv = min(n, m);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'B')
			{
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
				cnt++;
			}
		}
	}
	int len = max(r - l + 1, d - u + 1);
	if (len > minv) puts("-1");
	else if (len <= 0) puts("1");
	else printf("%d\n", len*len - cnt);

	return 0;
}