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
const int N = 1e6 + 10;
char s1[N];
char s2[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s1);
	scanf("%s", s2);
	int n = strlen(s1), m = strlen(s2);
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] ^ (s1[i] != s1[i - 1]);
	}
	int cur = 0;
	for (int i = 0; i < m; i++)
	{
		cur ^= (s1[i] != s2[i]);
	}
	int ans = cur ^ 1;
	for (int i = m; i < n; i++)
	{
		cur ^= a[i] ^ a[i - m];
		if (cur == 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}