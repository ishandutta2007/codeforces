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
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &m);
		int ans = INF;
		int o = 0;
		if (m == 1) m++, o = 1;
		for (int i = 0; i <= 10; i++)
		{
			int x = n;
			int cnt = o + i;
			while (x) x /= m, cnt++;
			ans = min(ans, cnt);
			m++;
		}
		printf("%d\n", ans);
		
	}
	return 0;
}