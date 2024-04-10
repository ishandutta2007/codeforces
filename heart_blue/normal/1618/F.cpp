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
const int N = 2e5 + 10;
string check(LL x)
{
	string ret;
	while (x)
	{
		ret += x % 2 + '0';
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
bool check(string s1, string s2)
{
	if (s1.find(s2) != s1.npos) return true;
	reverse(s2.begin(), s2.end());
	return s1.find(s2) != s1.npos;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	queue<string> q;
	map<string, int> ms;
	LL x, y;
	cin >> x >> y;
	string s1 = check(x);
	string s2 = check(y);
	q.push(s1);
	ms[s1] = 1;
	int flag = 0;
	while (!q.empty())
	{
		string s = q.front();
		q.pop();
		if (s == s2)
		{
			flag = 1;
			break;
		}
		string t = s;
		while (t.back() == '0') t.pop_back();
		reverse(t.begin(), t.end());
		if (ms[t] == 0)
		{
			ms[t] = 1;
			if (check(s2, t))
			{
				q.push(t);
			}
		}
		if (s.length() < s2.length())
		{
			s += '1';
			reverse(s.begin(), s.end());
			if (ms[s] == 0)
			{
				ms[s] = 1;
				if (check(s2, s))
				{
					q.push(s);
				}
			}
		}
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}