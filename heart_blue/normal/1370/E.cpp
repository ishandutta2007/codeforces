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
const int N = 1e6 + 10;
char s1[N];
char s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s%s", s1 + 1, s2 + 1);
	int ans = 0;
	int sz[2] = { 0,0 };
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s1[i] == s2[i]) continue;
		if (s1[i] == '0') tot++;
		else tot--;
		int x = s1[i] - '0';
		if (sz[x] == 0) sz[x] = 1, ans++;
		sz[x]--;
		sz[x ^ 1]++;
	}
	ans = sz[0] + sz[1];
	if (tot != 0) ans = -1;
	printf("%d\n", ans);
	return 0;
}