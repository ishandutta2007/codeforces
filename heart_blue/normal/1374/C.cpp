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
const int N = 2e5 + 10;
int solve(string& str)
{
	for (auto& c : str)
		c ^= '(' ^ ')';
	reverse(str.begin(), str.end());
	int cur = 0;
	int minv = 0;
	for (auto& c : str)
	{
		if (c == '(')
			cur++;
		else
			cur--;
		minv = min(minv, cur);
	}
	return -minv;
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		string str;
		cin >> n >> str;
		printf("%d\n", min(solve(str), solve(str)));
	}
	return 0;
}