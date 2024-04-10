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
const int N = 1e5 + 10;
int flag[N];
int mu[N];
int p[N];
vector<int> v[N];
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % INF;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) rfact[i] = (INF - INF / i) * rfact[INF % i] % INF;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i - 1] * rfact[i] % INF;
	mu[1] = 1;
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (flag[i] == 0)
		{
			mu[i] = -1;
			p[k++] = i;
		}
		for (int j = 0; p[j] * i < N; j++)
		{
			flag[i * p[j]] = 1;
			if (i % p[j] == 0) break;
			else mu[i * p[j]] = -mu[i];
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (mu[i] == 0) continue;
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
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
	init();
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n, f;
		scanf("%d%d", &n, &f);
		LL ans = 0;
		for (auto& d : v[n])
		{
			ans += mu[d] * C(n / d - 1, f - 1);
		}
		ans %= INF;
		if (ans < 0) ans += INF;
		printf("%lld\n", ans);
	}
	return 0;
}