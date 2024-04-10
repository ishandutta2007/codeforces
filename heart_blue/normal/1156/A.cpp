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
const int N = 1e2 + 10;
int a[N][N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 0;
	a[1][2] = 3;
	a[1][3] = 4;
	a[2][1] = 3;
	a[2][3] = INF;
	a[3][1] = 4;
	a[3][2] = INF;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) ans += a[b[i]][b[i + 1]];
	for (int i = 1; i + 2 <= n; i++)
	{
		if (b[i] == 3 && b[i + 1] == 1 && b[i + 2] == 2) ans--;
	}
	if (ans >= INF) puts("Infinite");
	else
	{
		puts("Finite");
		printf("%lld\n", ans);
	}
	return 0;
}