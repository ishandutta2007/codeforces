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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int phi[N];
LL sumphi[N];
void init()
{
	for (int i = 2; i < N; i++) phi[i] = i;
	for (int i = 2; i < N; i++)
	{
		if (phi[i] != i) continue;
		for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
	}
	for (int i = 2; i < N; i++)
	{
		sumphi[i] = phi[i] + sumphi[i - 1];
	}
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	init();
	if (m < n - 1)
	{
		puts("Impossible");
		return 0;
	}
	if (sumphi[n] < m)
	{
		puts("Impossible");
		return 0;
	}

	puts("Possible");
	for (int i = 1; i <= n; i++)
	{
		if (m == 0) break;
		for (int j = i + 1; j <= n; j++)
		{
			if (m == 0) break;
			if (gcd(i, j) == 1)
			{
				m--;
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}