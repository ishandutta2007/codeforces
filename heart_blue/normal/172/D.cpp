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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e7 + 10;
int a[N];
void init()
{
	for (int i = 2; i * i < N; i++)
	{
		int o = i * i;
		for (int j = o; j < N; j += o)
			a[j] = o;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, n;
	cin >> a >> n;
	init();
	int l = a, r = a + n - 1;
	LL ans = 0;
	for (int i = l; i <= r; i++)
		ans += i / max(1, ::a[i]);
	printf("%lld\n", ans);
	return 0;
}