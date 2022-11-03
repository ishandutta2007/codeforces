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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int o = (a + b) & 1;
		if (o)
		{
			if (a + d > 0) printf("Ya ");
			else printf("Tidak ");
			if (b + c > 0) printf("Ya ");
			else printf("Tidak ");
			puts("Tidak Tidak");
		}
		else
		{
			printf("Tidak Tidak ");
			if (b + c > 0) printf("Ya ");
			else printf("Tidak ");
			if (a + d > 0) printf("Ya");
			else printf("Tidak");
			puts("");
		}
	}
	return 0;
}