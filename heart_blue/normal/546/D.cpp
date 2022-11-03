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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e6 + 10;

LL a[N];
void init()
{
	MEM(a, 0);
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i; j < N; j += i)
		{
			int o = j;
			while (o%i == 0) o /= i, a[j]++;
		}
	}
	for (int i = 2; i < N; i++) a[i] += a[i - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	int r, l;
	while (ncase--)
	{
		scanf("%d%d", &r, &l);
		printf("%lld\n", a[r] - a[l]);
	}
	return 0;
}