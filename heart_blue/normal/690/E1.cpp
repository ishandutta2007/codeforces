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
const int N = 1e3 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int h, w;
		scanf("%d%d", &h, &w);
		for (int i = 1; i < h / 2; i++)
			for (int j = 1; j <= w; j++)
				scanf("%*d");
		for (int i = 1; i <= w; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= w; i++) scanf("%d", &b[i]);

		for (int i = 1; i < h / 2; i++)
			for (int j = 1; j <= w; j++)
				scanf("%*d");
		int cnt = 0;
		for (int i = 1; i <= w; i++)
		{
			if (abs(a[i] - b[i]) <= 50) cnt++;
		}
		if (w * 0.75 < cnt) puts("NO");
		else puts("YES");
	}
	return 0;
}