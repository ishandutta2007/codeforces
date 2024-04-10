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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str + 1);
		if (count(str + 1, str + n + 1, '1') & 1)
		{
			puts("NO");
			continue;
		}
		if (count(str + 1, str + n + 1, '1') == 0)
		{
			puts("NO");
			continue;
		}
		if (n == 2)
		{
			if (count(str + 1, str + n + 1, '1') != 2) puts("NO");
			else
			{
				puts("YES");
				puts("1 2");
			}
			continue;
		}
		fill(deg + 1, deg + n + 1, 0);
		int pos = find(str + 1, str + n + 1, '1') - str;
		vector<pair<int, int>> ans;
		vector<int> key;
		for (int i = 0; i < n; i++)
		{
			int x = pos + i;
			int y = pos + i + 1;
			if (x > n) x -= n;
			if (y > n) y -= n;
			if (str[y] == '0') ans.emplace_back(x, y), deg[x] ^= 1, deg[y] ^= 1;
			else key.emplace_back(x);
		}
		int rt = key[0];
		for (int i = 1; i < key.size(); i++)
		{
			ans.emplace_back(rt, key[i]);
			deg[rt] ^= 1;
			deg[key[i]] ^= 1;
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
			if (deg[i] != str[i] - '0')
				flag = 0;
		if (!flag) puts("NO");
		else
		{
			puts("YES");
			for (auto [x, y] : ans)
				printf("%d %d\n", x, y);
		}
	}
	return 0;
}