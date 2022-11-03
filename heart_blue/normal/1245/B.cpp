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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		string str;
		cin >> str;
		string ans;
		int tot = 0;
		for (auto& c : str)
		{
			int o = 0;
			if (c == 'R') o = 0;
			else if (c == 'P') o = 1;
			else o = 2;
			int o1 = o + 1;
			int o0 = o - 1;
			if (o1 > 2) o1 -= 3;
			if (o0 < 0) o0 += 3;
			if (a[o1] > 0)
			{
				a[o1]--;
				ans.push_back("RPS"[o1]);
				tot++;
			}
			else ans.push_back('0');
		}
		int cur = 0;
		for (auto& c : ans)
		{
			if (c == '0')
			{
				while (a[cur] == 0)cur++;
				c = "RPS"[cur];
				a[cur]--;
			}
		}
		if (tot >= (n + 1) / 2) puts("YES"), puts(ans.c_str());
		else puts("NO");
	}
	return 0;
}