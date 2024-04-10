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
const int N = 1e3 + 10;
void refrain(string& str)
{
	if (str.length() <= 1) return;
	string key;
	key.push_back(str.front());
	key.push_back(str.back());
	str = key;
}
pair<string, LL> add(pair<string, LL>& p1, pair<string, LL>& p2)
{
	string str = p1.first + p2.first;
	int cnt = 0;
	if (p1.first.back() == 'A' && p2.first.front() == 'C')
		cnt = 1;
	refrain(str);
	return make_pair(str, p1.second + p2.second + cnt);
}
string build(string str, int cnt)
{
	int len = str.length();
	if (str.front() == 'A' && str.back() == 'C' && cnt > 1)
		return "";
	if (cnt == 0)
	{
		if (str.front() == str.back())
			return string(len, str.front());
		else
			return str;
	}
	if (str.length() == 1) return "";
	if (str.length() == 2)
	{
		if (cnt == 1 && str == "AC") return str;
		else return "";
	}
	int cur = len - 1;
	if (str.back() == 'C')
	{
		str[cur - 1] = 'A';
		cur -= 2, cnt--;
	}
	else cur--;
	while (cur > 0 && cnt > 0)
	{
		if (str[cur - 1] == 'B') str[cur] = 'C', str[cur - 1] = 'A', cnt--, cur -= 2;
		else break;
	}
	if (cnt == 0) return str;
	else return "";
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string ac = "ABC";
	int k, x, n, m;
	cin >> k >> x >> n >> m;
	for (int o1 = 0; o1 < 3; o1++)
	{
		for (int o2 = 0; o2 < 3; o2++)
		{
			for (int o3 = 0; o3 < 3; o3++)
			{
				for (int o4 = 0; o4 < 3; o4++)
				{
					string ss1 = string(n, 'B');
					string ss2 = string(m, 'B');
					ss1.front() = ac[o1];
					ss1.back() = ac[o2];
					ss2.front() = ac[o3];
					ss2.back() = ac[o4];
					for (int i = 0; i <= n / 2; i++)
					{
						string s1 = build(ss1, i);
						if (s1.empty()) continue;
						for (int j = 0; j <= m / 2; j++)
						{
							string s2 = build(ss2, j);
							if (s2.empty()) continue;
							pair<string, LL> p1 = { s1,i * 1LL };
							pair<string, LL> p2 = { s2,j * 1LL };
							for (int t = 3; t <= k; t++)
							{
								tie(p2, p1) = make_pair(add(p1, p2), p2);
							}
							if (p2.second == x)
							{
								cout << s1 << endl;
								cout << s2 << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "Happy new year!" << endl;
	return 0;
}