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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int cnt;
		char ch[10];
		char c;
		scanf("%d%s", &cnt, ch);
		c = ch[0];
		int ans = 0;
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			while (p < n && cnt >= 0)
			{
				if (c != str[p])
				{
					cnt--;
					if (cnt < 0)
					{
						cnt = 0;
						break;
					}
				}
				p++;
			}
			ans = max(ans, p - i);
			if (str[i] != c) cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}