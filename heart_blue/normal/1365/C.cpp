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
const int N = 2e5 + 10;
int a[N];
int b[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		b[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int r = b[i] - a[i];
		if (r < 0) r += n;
		cnt[r]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}