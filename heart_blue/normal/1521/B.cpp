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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
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
		int key = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] < a[key])
				key = i;
		}
		if (key != 1) printf("%d\n", n);
		else printf("%d\n", n - 1);
		if (key != 1)
		{
			printf("%d %d %d %d\n", 1, key, a[key], a[1]);
			swap(a[key], a[1]);
		}
		for (int i = 2; i <= n; i++)
		{
			printf("%d %d %d %d\n", 1, i, a[1], a[1] + i - 1);
		}
	}
	return 0;
}