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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int cnt[N];
bool check(string& s1, string& s2)
{
	int ptr = 0;
	for (auto& c : s1)
	{
		while (ptr < s2.length() && s2[ptr] != c) ptr++;
		if (ptr == s2.length()) return false;
		ptr++;
	}
	return true;
}
void add(string& s, int o)
{
	for (auto& c : s) 
		cnt[c] += o;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string s, t, p;
		cin >> s >> t >> p;
		if (!check(s, t))
		{
			puts("NO");
			continue;
		}
		MEM(cnt, 0);
		add(s, 1);
		add(p, 1);
		add(t, -1);
		int flag = 1;
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (cnt[i] < 0) flag = 0;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}