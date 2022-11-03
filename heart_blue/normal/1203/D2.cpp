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
const int N = 2e5 + 10;
char s1[N];
char s2[N];
int pos1[N];
int pos2[N];
void check(int n, int m, int pos[])
{
	int ptr = 1;
	for (int i = 1; i <= m; i++)
	{
		while (s1[ptr] != s2[i]) ptr++;
		pos[i] = ptr++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	check(n, m, pos1);
	reverse(s1 + 1, s1 + n + 1);
	reverse(s2 + 1, s2 + m + 1);
	check(n, m, pos2);
	reverse(pos2 + 1, pos2 + m + 1);
	for (int i = 1; i <= m; i++) pos2[i] = n - pos2[i] + 1;
	int ans = max(n - pos1[m], pos2[1] - 1);
	for (int i = 1; i < m; i++)
	{
		ans = max(ans, pos2[i + 1] - pos1[i] - 1);
	}
	cout << ans << endl;
	return 0;
}