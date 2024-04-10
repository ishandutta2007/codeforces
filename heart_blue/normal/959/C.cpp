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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 5)
	{
		puts("-1");
	}
	else
	{
		puts("1 2");
		puts("2 3");
		puts("2 4");
		for (int i = 5; i <= n; i++)
		{
			printf("1 %d\n", i);
		}
	}
	for (int i = 2; i <= n; i++)
	{
		printf("1 %d\n", i);
	}
	return 0;

	return 0;
}