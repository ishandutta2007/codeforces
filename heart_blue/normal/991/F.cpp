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
const int N = 1e5 + 10;
int len[N];
map<LL, pair<int, int>> mc;
void init()
{
	len[0] = 0;
	for (int i = 1; i < N; i++) len[i] = len[i / 10] + 1;
}
string combine(int x, int p1, int y, int p2, char c)
{
	return to_string(x) + "^" + to_string(p1) + c
		+ to_string(y) + "^" + to_string(p2);
}
string refrain(int x)
{
	string str = to_string(x);
	pair<int, string> ans = { int(str.length()),str };
	if (mc.count(x))
	{
		int y, p;
		tie(y, p) = mc[x];
		string s = to_string(y) + "^" + to_string(p);
		ans = min(ans, { int(s.length()), s });
	}
	return ans.second;
}
string combine(int a, int b, int c, int d)
{
	string ret;
	if (a != 1) ret = refrain(a) + "*";
	ret += to_string(b) + "^" + to_string(c);
	if (d != 0) ret += "+" + refrain(d);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL n;
	cin >> n;
	string str = to_string(n);
	int l = str.length();
	if (n == 10000000000LL)
	{
		cout << "10^10" << endl;
		return 0;
	}
	if (l < 4)
	{
		cout << n << endl;
		return 0;
	}
	int minv = l;
	for (int i = 2; 1LL * i*i <= n; i++)
	{
		LL cur = 1LL * i * i;
		int cnt = 1;
		while (cur <= n)
		{
			cnt++;
			if (len[i] + 1 + len[cnt] >= l) break;
			if (cur >= 1000)
			{
				if (mc.count(cur))
				{
					int x, p;
					tie(x, p) = mc[cur];
					if (len[x] + 1 + len[p] > len[i] + 1 + len[cnt])
					{
						mc[cur] = { i,cnt };
					}
				}
				else mc[cur] = { i,cnt };
			}
			cur *= i;
		}
	}
	pair<int, string> ans = { l,str };
	for (auto &pp : mc)
	{
		LL x = pp.first;
		if (mc.count(n - x))
		{
			int y, p;
			tie(y, p) = mc[n - x];
			string s = combine(pp.second.first, pp.second.second, y, p, '+');
			ans = min(ans, { (int)s.length(),s });
		}
		if (n%x == 0 && mc.count(n / x))
		{
			int y, p;
			tie(y, p) = mc[n / x];
			string s = combine(pp.second.first, pp.second.second, y, p, '*');
			ans = min(ans, { (int)s.length(),s });
		}
		int y, p;
		tie(y, p) = pp.second;
		string s = combine(n / x, y, p, n%x);
		ans = min(ans, { (int)s.length(),s });
	}
	cout << ans.second << endl;
	return 0;
}