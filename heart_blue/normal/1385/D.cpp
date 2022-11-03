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
char str[N];
int solve(int l, int r, char c)
{
	if (l == r)
	{
		return str[l] != c;
	}
	int mid = (l + r) / 2;
	int len = (r - l + 1) / 2;
	return min(len - count(str + l, str + mid + 1, c) + solve(mid + 1, r, c + 1),
		len - count(str + mid + 1, str + r + 1, c) + solve(l, mid, c + 1));
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
		scanf("%s", str + 1);
		printf("%d\n", solve(1, n, 'a'));
	}
	return 0;
}