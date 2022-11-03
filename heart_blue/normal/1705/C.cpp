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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
pair<LL, LL> p[100];
LL len[100];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		scanf("%s", str + 1);
		len[0] = n;
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld%lld", &p[i].first, &p[i].second);
			len[i] = len[i - 1] + p[i].second - p[i].first + 1;
		}
		while (q--)
		{
			LL k;
			scanf("%lld", &k);
			for (int i = m; i >= 1; i--)
			{
				auto [l, r] = p[i];
				if (k > len[i - 1])
				{
					k -= len[i - 1];
					k = k - 1 + l;
				}
			}
			printf("%c\n", str[k]);
		}
	}
	return 0;
}