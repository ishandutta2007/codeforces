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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	str[0] = '*';
	str[n + 1] = '*';
	str[n + 2] = 0;
	int ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '.')
		{
			if (cur > 0) ans++;
			cur++;
		}
		else cur = 0;
	}
	while (m--)
	{
		int pos;
		char c[2];
		scanf("%d%s", &pos, c);
		int o = 0;
		if (str[pos - 1] == '.') o++;
		if (str[pos + 1] == '.') o++;
		if (isalpha(str[pos]) == isalpha(c[0]))
		{
			printf("%d\n", ans);
			continue;
		}
		if (c[0] == '.') ans += o;
		else ans -= o;
		printf("%d\n", ans);
		str[pos] = c[0];
	}
	return 0;
}