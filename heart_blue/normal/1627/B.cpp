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
const int N = 2e5 + 20;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int dx[] = { 1,1,n,n };
		int dy[] = { 1,m,1,m };
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int maxv = 0;
				for (int o = 0; o < 4; o++)
				{
					maxv = max(maxv, abs(i - dx[o]) + abs(j - dy[o]));
				}
				v.push_back(maxv);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n * m; i++)
			printf("%d ", v[i]);
		puts("");
	}
	return 0;
}