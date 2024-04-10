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
int ans[N];
int flag[N];
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		ans[i]++;
		if (1LL * i * i < N) ans[i * i]--;
		for (int j = i + i; j < N; j += i) flag[j] = 1;
	}
	ans[1] = 1;
	for (int i = 2; i < N; i++)
		ans[i] += ans[i - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}