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
const int N = 1e5 + 10;
const int M = 2e6 + 10;
pair<int, int> refrain(string& str)
{
	int l = count(str.begin(), str.end(), '&');
	int r = count(str.begin(), str.end(), '*');
	str = str.substr(l, str.length() - r - l);
	return { l,r };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<string, int> ms;
	ms["void"] = 0;
	while (n--)
	{
		string op;
		cin >> op;
		if (op.length() == 7)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int l, r;
			tie(l, r) = refrain(s1);
			if (!ms.count(s1) || ms[s1] == -INF)
			{
				ms[s2] = -INF;
				continue;
			}
			int o = ms[s1] - l + r;
			if (o < 0) o = -INF;
			ms[s2] = o;
		}
		else
		{
			string str;
			int l, r;
			cin >> str;
			tie(l, r) = refrain(str);
			if (!ms.count(str))
			{
				puts("errtype");
				continue;
			}
			int o = ms[str] - l + r;
			if (o < 0)
			{
				puts("errtype");
				continue;
			}
			puts(("void" + string(o, '*')).c_str());
		}
	}
	return 0;
}