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
const int N = 3e5 + 10;
int ans[N];
char str[N];
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
		scanf("%s", str + 1);
		char pre = 0;
		int cur = 0;
		ans[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (str[i] != pre) cur++;
			else cur = 1;
			pre = str[i];
			ans[i] = 0;
			if (str[i] == 'L') ans[i] = cur;
		}
		cur = 0;
		pre = 0;
		for (int i = n; i > 0; i--)
		{
			if (str[i] != pre) cur++;
			else cur = 1;
			pre = str[i];
			if (str[i] == 'R') ans[i - 1] += cur;
		}
		for (int i = 0; i <= n; i++)
			printf("%d ", ans[i] + 1);
		puts("");
	}

	return 0;
}