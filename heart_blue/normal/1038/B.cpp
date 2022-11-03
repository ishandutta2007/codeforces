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
const int N = 1e4 + 10;
vector<int> v[2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int x;
	if (n & 1) x = (n + 1) / 2;
	else x = n / 2;
	printf("1 %d\n", x);
	printf("%d", n - 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		printf(" %d", i);
	}
	return 0;
}