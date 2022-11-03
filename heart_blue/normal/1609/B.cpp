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
const int N = 2e5 + 10;
char str[N];
int flag[N];
int check(int x)
{
	if (x <= 0) return 0;
	return str[x] == 'a' && str[x + 1] == 'b' && str[x + 2] == 'c' ? 1 : 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += check(i);
	}
	while (q--)
	{
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		for (int j = 0; j < 3; j++)
			ans -= check(pos - j);
		str[pos] = c;
		for (int j = 0; j < 3; j++)
			ans += check(pos - j);
		printf("%d\n", ans);
	}
	return 0;
}