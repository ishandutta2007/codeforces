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
#include <cassert>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b) puts("0");
		else if (abs(a - b) >= x) puts("1");
		else if (abs(a - l) >= x && abs(l - b) >= x) puts("2");
		else if (abs(a - r) >= x && abs(r - b) >= x) puts("2");
		else if (abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x) puts("3");
		else if (abs(a - l) >= x && abs(r - l) >= x && abs(r - b) >= x) puts("3");
		else puts("-1");
	}
	return 0;
}