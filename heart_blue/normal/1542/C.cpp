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
const int N = 1e5 + 10;
const int M = 43;
LL key[M];
LL ans[M];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	key[1] = 1;
	for (int i = 2; i < M; i++)
	{
		key[i] = i / gcd(i, key[i - 1]) * key[i - 1];
		//cout << key[i] << endl;
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		for (int i = M - 1; i >= 1; i--)
		{
			ans[i] = n / key[i];
			if (ans[i] == 0) continue;
			if (key[i] == key[i + 1])
			{
				ans[i] = 0;
				continue;
			}
			for (int j = i + 1; j < M; j++)
			{
				ans[i] -= ans[j];
			}
		}
		LL res = 0;
		for (int i = 1; i < M; i++)
		{
			ans[i] %= INF;
			res += ans[i] * (i + 1) % INF;
		}
		printf("%lld\n", res % INF);
	}
	return 0;
}