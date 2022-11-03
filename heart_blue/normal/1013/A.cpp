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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		sum1 += x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		sum2 += x;
	}
	if (sum1 >= sum2) puts("Yes");
	else puts("No");
	return 0;
}