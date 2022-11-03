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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		a[val]++;
	}
	for (int i = 1; i < x; i++)
	{
		a[i + 1] += a[i] / (i + 1);
		if (a[i] % (i + 1))
			puts("No"), exit(0);
	}
	puts("Yes");
	return 0;
}