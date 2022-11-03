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
const int N = 2e6 + 10;
char str[N];
char s[N];
int d[N];
void build(int n)
{
	s[0] = '!';
	for (int i = 1; i <= n; i++)
	{
		s[2 * i - 1] = str[i];
		s[2 * i] = '*';
	}
	s[2 * n] = '#';
}
int check(int l, int r)
{
	int cnt = 0;
	while (l < r)
	{
		if (str[l] == str[r]) cnt++;
		else break;
		l++, r--;
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		if (abs(n - k) & 1) puts("NO");
		else if (1LL * k * k > n) puts("NO");
		else puts("YES");
	}
	return 0;
}