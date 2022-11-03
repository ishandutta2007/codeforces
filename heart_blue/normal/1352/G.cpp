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
const int N = 8e3 + 10;
int a[N];
int flag[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	// 2 4 1 3     
	// 2 4 1 3 5
	// 1 3 5 2 4 6
	// 1 4 6 2 5 3 7
	while (ncase--)
	{
		int n;
		cin >> n;
		if (n <= 3)
		{
			puts("-1");
			continue;
		}
		int cur = 0;
		if (n % 4 == 0) cur = 1;
		if (n % 4 == 1) printf("2 4 1 3 5 "), cur = 6;
		if (n % 4 == 2) printf("1 3 5 2 4 6 "), cur = 7;
		if (n % 4 == 3) printf("1 4 6 2 5 3 7 "), cur = 8;
		while (cur + 3 <= n)
		{
			printf("%d %d %d %d ", cur + 1, cur + 3, cur, cur + 2);
			cur += 4;
		}
		puts("");
	}
	return 0;
}