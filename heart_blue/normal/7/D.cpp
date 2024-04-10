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
const int N = 5e6 + 10;
char str[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL p = 0;
	LL q = 0;
	LL m = 1239;
	LL a = 1;
	scanf("%s", str + 1);
	int ans = 0;
	for (int i = 1; str[i]; i++)
	{
		p = (p * m + str[i]);
		q = (q + str[i] * a);
		a = a * m;
		if (p == q)
		{
			deg[i] = deg[i >> 1] + 1;
			ans += deg[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}