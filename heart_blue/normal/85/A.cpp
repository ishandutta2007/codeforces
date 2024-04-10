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
const int N = 2e3 + 10;
char ans[4][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, 0);
	int n;
	cin >> n;
	int cur = 0;
	ans[0][0] = ans[1][0] = cur + 'a';
	cur++;
	for (int i = 0; i + 1 < n; i++)
	{
		for (int o = 0; o < 4; o++)
		{
			if (ans[o][i]) continue;
			ans[o][i] = cur % 26 + 'a';
			ans[o][i + 1] = cur % 26 + 'a';
			cur++;
		}
	}
	for (int o = 0; o < 4; o++)
	{
		if (ans[o][n - 1] == 0)
		{
			ans[o][n - 1] = cur % 26 + 'a';
		}
		puts(ans[o]);
	}
	return 0;
}