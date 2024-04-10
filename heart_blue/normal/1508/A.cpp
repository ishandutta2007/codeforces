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
const int N = 2e5 + 10;
int flag[N];
string getans(string& s1, string& s2, char c)
{
	int cnt1 = count(s1.begin(), s1.end(), c);
	int cnt2 = count(s2.begin(), s2.end(), c);
	int tot = max(cnt1, cnt2);
	s1 += c;
	s2 += c;
	memset(flag, 0, sizeof(int) * (tot + 1));
	int cnt = 0;
	for (int i = 0, cur = 0; i < s1.length(); i++)
	{
		if (s1[i] == c)
		{
			flag[cur] = max(flag[cur], cnt);
			cnt = 0;
			cur++;
		}
		else
			cnt++;
	}
	cnt = 0;
	for (int i = 0, cur = 0; i < s2.length(); i++)
	{
		if (s2[i] == c)
		{
			flag[cur] = max(flag[cur], cnt);
			cnt = 0;
			cur++;
		}
		else
			cnt++;
	}
	s1.pop_back();
	s2.pop_back();
	string ret;
	for (int i = 0; i <= tot; i++)
	{
		while (flag[i]--)
			ret += c ^ 1;
		ret += c;
	}
	ret.pop_back();
	return ret;
}
void solve(vector<string>& vs, int limit)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			for (int o = 0; o < 2; o++)
			{
				string ans = getans(vs[i], vs[j], o + '0');
				if (ans.length() <= limit)
				{
					puts(ans.c_str());
					return;
				}
			}
		}
	}
}
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
		vector<string> vs(3);
		for (int i = 0; i < 3; i++)
		{
			cin >> vs[i];
		}
		string ans;
		solve(vs, n * 3);
	}

	return 0;
}