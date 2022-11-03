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
int p[N];
int phi[N];
int k = 0;
void init()
{
	for (int i = 1; i < N; i++) phi[i] = i;
	for (int i = 2; i < N; i++)
	{
		if (phi[i] != i) continue;
		for (int j = i; j < N; j += i) phi[j] = phi[j] / i * (i - 1);
		p[k++] = i;
	}
}
LL getphi(LL x)
{
	if (x < N) return phi[x];
	LL ret = x;
	for (int i = 0; 1LL * p[i] * p[i] <= x; i++)
	{
		if (x%p[i]) continue;
		while (x%p[i] == 0) x /= p[i];
		ret = ret / p[i] * (p[i] - 1);
	}
	if (x > 1) ret = ret / x * (x - 1);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, tot;
	init();
	cin >> n >> tot;
	tot = (tot + 1) / 2;
	while (tot-- && n > 1)
	{
		n = getphi(n);
	}
	printf("%lld\n", n%INF);
	return 0;
}