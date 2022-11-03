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
char str[N];
set<int> s[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		s[str[i]].insert(i);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int pos;
			char c;
			scanf("%d %c", &pos, &c);
			s[str[pos]].erase(pos);
			str[pos] = c;
			s[c].insert(pos);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = 0;
			for (int i = 'a'; i <= 'z'; i++)
			{
				auto iter = s[i].lower_bound(l);
				if (iter != s[i].end() && *iter <= r) ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}