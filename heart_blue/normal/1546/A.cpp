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
const int N = 1e5 + 10;
int a[N];
int b[N];
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
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum1 += a[i];
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]), sum2 += b[i];
		if (sum1 != sum2)
		{
			puts("-1");
			continue;
		}
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > b[i])
			{
				int o = a[i] - b[i];
				while (o--)
					v1.push_back(i);
			}
			if (a[i] < b[i])
			{
				int o = b[i] - a[i];
				while (o--)
					v2.push_back(i);
			}
		}
		printf("%d\n", v1.size());
		for (int i = 0; i < v1.size(); i++)
		{
			printf("%d %d\n", v1[i], v2[i]);
		}
	}
	return 0;
}