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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a = 0, b = 0, sum = 0;
	string s1, s2;
	int n;
	cin >> n >> s1 >> s2;
	n *= 2;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '1' && s2[i] == '1') sum++;
		else if (s1[i] == '1') a++;
		else if (s2[i] == '1') b++;
	}
	sum &= 1;
	int o = sum;
	while (a > 0 || b > 0)
	{
		if (o == 0)
		{
			if (a > 0) a--, sum++;
			else b--;
		}
		else
		{
			if (b > 0) b--, sum--;
			else a--;
		}
		o ^= 1;
	}
	if (sum > 0) puts("First");
	else if (sum == 0) puts("Draw");
	else puts("Second");
	return 0;
}