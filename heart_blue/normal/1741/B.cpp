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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int check(string str)
{
	if (str == "M") return 0;
	if (str.back() == 'S') return -str.length();
	else return str.length();
}
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
		if (n == 3) puts("-1");
		else if (n % 2 == 0)
		{
			for (int i = n; i >= 1; i--)
				printf("%d%c", i, " \n"[i == 1]);
		}
		else
		{
			printf("%d %d ", n, n - 1);
			for (int i = 1; i <= n - 2; i++)
				printf("%d%c", i, " \n"[i == n - 2]);
		}
	}
	return 0;
}