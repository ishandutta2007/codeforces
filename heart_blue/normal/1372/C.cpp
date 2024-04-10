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

int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = (i + 1) != x;
		}
		int tot = count(a, a + n, 1);
		if (tot == 0)
		{
			puts("0");
			continue;
		}
		int pos = find(a, a + n, 1) - a;
		int cnt = 0;
		for (int i = pos; i < n; i++)
		{
			if (a[i]) cnt++;
			else break;
		}
		if (tot == cnt) puts("1");
		else puts("2");
	}
	return 0;
}