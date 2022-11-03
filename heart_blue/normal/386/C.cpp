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
const int N = 2e6 + 10;
int cnt[200];
LL ans[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	map<char, int> mc;
	for (auto& c : str)
		mc[c]++;
	for (int o = 1; o <= mc.size(); o++)
	{
		MEM(cnt, 0);
		int ptr = 0;
		int tot = 0;
		for (int i = 0; i < str.length(); i++)
		{
			while (ptr < str.length() && tot <= o)
			{
				if (cnt[str[ptr]] == 0 && tot >= o)
					break;
				if (cnt[str[ptr]]++ == 0)
					tot++;
				ptr++;
			}
			ans[o] += ptr - i;
			if (cnt[str[i]]-- == 1)
				tot--;
		}
	}
	for (int i = mc.size(); i >= 1; i--)
		ans[i] -= ans[i - 1];
	printf("%d\n", mc.size());
	for (int i = 1; i <= mc.size(); i++)
		printf("%lld\n", ans[i]);
	return 0;
}