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
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
const int M = 7e2 + 10;
int a[M][M];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			b[x] += y;
			for (int i = 1; i < M; i++)
				a[i][x % i] += y;
		}
		else
		{
			int ans = 0;
			if (x < M)
				ans = a[x][y];
			else
				for (int i = y; i < N; i += x)
					ans += b[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}