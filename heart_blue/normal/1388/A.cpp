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
const int N = 3e5 + 10;
void solve()
{
	int a[] = { 6,10,14,15 };
	int n;
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				int x = n - a[i] - a[j] - a[k];
				if (x <= 0) continue;
				if (x == a[i] || x == a[j] || x == a[k]) continue;
				puts("YES");
				printf("%d %d %d %d\n", a[i], a[j], a[k], x);
				return;
			}
		}
	}
	puts("NO");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		solve();
	}
	return 0;
}