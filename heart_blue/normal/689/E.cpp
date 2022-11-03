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
const int N = 2e5 + 10;
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = i * fact[i - 1] % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++)
		rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++)
		rfact[i] = rfact[i - 1] * rfact[i] % INF;
}
LL C(int n, int m)
{
	if (n < m) return 0;
	return fact[n] * rfact[m] % INF * rfact[n - m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	init();
	scanf("%d%d", &n, &k);
	map<int, int> mc;
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		mc[l]++;
		mc[r + 1]--;
	}
	int sum = 0;
	LL ans = 0;
	int pre = -INF;
	for (auto& p : mc)
	{
		ans += C(sum, k) * (p.first - pre) % INF;
		pre = p.first;
		sum += p.second;
	}
	printf("%lld\n", ans % INF);
	return 0;
}