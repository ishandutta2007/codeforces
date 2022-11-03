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
const int N = 5e3 + 10;
int a[N];
LL tot[N];
LL suf[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(tot, 0);
	MEM(suf, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j] > a[i]) tot[a[j] - a[i]]++;
		}
	}
	memcpy(suf, tot, sizeof(suf));
	for (int i = N - 2; i >= 0; i--) suf[i] += suf[i + 1];
	LL ans = 0;
	LL d = 0;
	int o = n*(n - 1) / 2;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j + 1 < N; j++)
		{
			ans += tot[i] * tot[j] * suf[i + j + 1];
			d += ans / o;
			ans %= o;
		}
	}
	printf("%.15f\n", (d + 1.0*ans / o) / o / o);
	return 0;
}