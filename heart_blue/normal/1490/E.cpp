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
int a[N];
LL b[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) sum[i] = b[i] + sum[i - 1];
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			LL x = a[i];
			while (1)
			{
				int pos = upper_bound(b + 1, b + n + 1, x) - b - 1;
				if (x == sum[pos]) break;
				x = sum[pos];
			}
			if (x >= b[n])
				v.push_back(i);
		}
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++)
			printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
	}
	return 0;
}